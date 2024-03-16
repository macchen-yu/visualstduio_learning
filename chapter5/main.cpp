#include <iostream>
#include <vector>
#include <algorithm>

static const size_t g_graphics_number = 16;

class Painter {};

class Graphic
{
public:
    virtual ~Graphic() = default;

    virtual std::string name() const = 0;
    virtual float size() const = 0;
    virtual int draw(Painter* painter) = 0;
};

class Triangle : public Graphic
{
public:
    Triangle(const std::string& id, float h, float b)
        : name_(id),
        height_(h),
        base_(b)
    {}
    virtual ~Triangle() override = default;

    virtual std::string name() const override
    {
        return "Triangle_" + name_;
    }

    virtual float size() const override
    {
        return 0.5f * height_ * base_;
    }

    virtual int draw(Painter* painter) override
    {
        std::cout << "[info] Draw Triangle(" << name_ << ") Using Painter." << std::endl;
        return 0;
    }

private:
    std::string name_;
    float height_{ 0 };
    float base_{ 0 };
};


class Square : public Graphic
{
public:
    Square(const std::string& id, float l)
        : name_(id),
        side_length_(l)
    {}
    virtual ~Square() override = default;

    virtual std::string name() const override
    {
        return "Square_" + name_;
    }

    virtual float size() const override
    {
        return side_length_ * side_length_;
    }

    virtual int draw(Painter* painter) override
    {
        std::cout << "[info] Draw Square(" << name_ << ") Using Painter." << std::endl;
        return 0;
    }

private:
    std::string name_;
    float side_length_;
};

class GraphicProxy
{
public:
    ~GraphicProxy()
    {
        for (auto itor = graphics_.begin();
            itor != graphics_.end(); ++itor)
        {
            delete* itor;
        }
        graphics_.clear();
    }

    void add_graphic(Graphic* g)
    {
        graphics_.push_back(g);
    }

    void remove_graphic(size_t index)
    {
        if (index > graphics_.size())
            return;

        graphics_.erase(graphics_.begin() + index);
    }

    int draw(Painter* painter)
    {
        for (auto& g : graphics_)
        {
            g->draw(painter);
        }
        return 0;
    }

    Graphic* find_graphic(const std::string& key)
    {
        auto is_name_contain_key = [key](const Graphic* g)
        {
            const std::string& graph_name = g->name();
            unsigned position = graph_name.find(key);
            return position != graph_name.npos;
        };

        auto found = std::find_if(graphics_.begin(),
            graphics_.end(), is_name_contain_key);

        if (found != graphics_.end())
            return *found;
        else
            return nullptr;
    }

private:
    std::vector<Graphic*> graphics_;
};

int main()
{
    GraphicProxy graphics;

    // Create some Triangle and Square
    char buffer[64];
    int id_start = -8;

    for (int id = id_start; id < g_graphics_number - std::abs(id_start); ++id)
    {
        sprintf_s(buffer, "%d", id);
        graphics.add_graphic(new Triangle(buffer, id + 1, 2 * (id + 1)));
    }

    for (int id = 0; id < g_graphics_number; ++id)
    {
        sprintf_s(buffer, "%d", id);
        graphics.add_graphic(new Square(buffer, 2 * id + 1));
    }

    Painter painter;
    graphics.draw(&painter);

    auto g = graphics.find_graphic("Square_10");
    if (g)
    {
        std::cout << "Graphic: " << g->name()
            << ", size: " << g->size();
    }

    return 0;
}

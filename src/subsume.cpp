#include <concepts>
#include <iostream>

template <typename T>
concept Drawable = requires(T obj) {
    { obj.draw() } -> std::same_as<void>;
};

template <typename T>
concept ColoredDrawable = Drawable<T> && requires(T obj) {
    { obj.set_color(std::string{}) } -> std::same_as<void>;
};

class Circle {
public:
    void draw() { std::cout << "Drawing a circle" << std::endl; }
};

class ColoredCircle {
public:
    void draw() { std::cout << "Drawing a colored circle" << std::endl; }
    void set_color(const std::string& color) {
        std::cout << "Setting color to: " << color << std::endl;
    }
};

// Funktion som enbart tar Drawable-objekt
template <Drawable T>
void perform_draw(T& obj) {
    obj.draw();
}

// Funktion som enbart tar ColoredDrawable-objekt
template <ColoredDrawable T>
void perform_draw_and_set_color(T& obj, const std::string& color) {
    obj.set_color(color);
    obj.draw();
}

int main() {
    Circle circle;
    ColoredCircle colored_circle;

    perform_draw(circle); // OK, fungerar med Drawable
    perform_draw(colored_circle); // OK, fungerar med ColoredDrawable, eftersom ColoredDrawable subsumes Drawable

    // perform_draw_and_set_color(circle, "red"); // Fel: Circle uppfyller inte ColoredDrawable-conceptet
    perform_draw_and_set_color(colored_circle, "red"); // OK, fungerar med ColoredDrawable

    return 0;
}


#include <iostream>
#include <concepts>
#include <string>

// 1. The Base Concept
template <typename T>
concept Renderable = requires(T obj) {
    { obj.render() } -> std::same_as<void>;
};

// 2. The Subsuming Concept
// CRITICAL: You MUST use the exact name of the base concept (Renderable<T>) 
// on the left side of the && operator. This is the only way the compiler 
// can mathematically prove that AdvancedRenderable is a strict superset of Renderable.
template <typename T>
concept AdvancedRenderable = Renderable<T> && requires(T obj) {
    { obj.apply_shader(std::string{}) } -> std::same_as<void>;
};

// 3. The Data Types (Notice there is no inheritance or virtual tables here)
struct BasicModel {
    void render() { std::cout << "Rendering basic wireframe.\n"; }
};

struct HighResModel {
    void render() { std::cout << "Rendering high-res mesh.\n"; }
    void apply_shader(const std::string& shader) {
        std::cout << "Applying shader: " << shader << "\n";
    }
};

// =====================================================================
// 4. Overload Resolution via Subsumption
// =====================================================================

// Overload A: Catch-all for basic Renderable types
template <Renderable T>
void draw_scene(T& item) {
    std::cout << "[Basic Path] ";
    item.render();
}

// Overload B: Specialized path for AdvancedRenderable types.
// HighResModel satisfies BOTH Overload A and Overload B. 
// Because AdvancedRenderable subsumes Renderable, the compiler knows 
// this overload is "more constrained" and automatically picks it 
// without throwing an ambiguous overload error.
template <AdvancedRenderable T>
void draw_scene(T& item) {
    std::cout << "[Advanced Path] ";
    item.apply_shader("RayTracing_v1");
    item.render();
}

int main() {
    BasicModel wall;
    HighResModel hero_character;

    std::cout << "--- Drawing Wall ---\n";
    
    // The compiler checks 'wall'. It only satisfies Renderable.
    // It routes to Overload A.
    draw_scene(wall); 

    std::cout << "\n--- Drawing Hero ---\n";
    
    // The compiler checks 'hero_character'. It satisfies BOTH concepts.
    // Subsumption kicks in. The compiler mathematically proves Overload B 
    // is stricter than Overload A, and perfectly routes the call.
    draw_scene(hero_character); 

    return 0;
}
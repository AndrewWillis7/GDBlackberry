// shape_generator.h
#ifndef SHAPE_GENERATOR_H
#define SHAPE_GENERATOR_H

#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/box_mesh.hpp>
#include <godot_cpp/classes/sphere_mesh.hpp>
#include <godot_cpp/classes/collision_shape3d.hpp>
#include <godot_cpp/classes/box_shape3d.hpp>

using namespace godot;

class ShapeGenerator : public EditorPlugin {
    GDCLASS(ShapeGenerator, EditorPlugin);

protected:
    static void _bind_methods();

public:
    void _enter_tree() override;
    void _exit_tree() override;

    void _generate_cube_with_collision();
    void _generate_sphere_with_collision();

private:
    void _add_to_scene(Node *node);
};

#endif // SHAPE_GENERATOR_H
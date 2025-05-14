// shape_generator.cpp
#include "shape_generator.h"
#include <godot_cpp/classes/editor_interface.hpp>

void ShapeGenerator::_bind_methods() {
    // Bind methods if needed
}

void ShapeGenerator::_enter_tree() {
    add_tool_menu_item("Generate Cube", callable_mp(this, &ShapeGenerator::_generate_cube_with_collision));
    add_tool_menu_item("Generate Sphere", callable_mp(this, &ShapeGenerator::_generate_sphere_with_collision));
}

void ShapeGenerator::_exit_tree() {
    remove_tool_menu_item("Generate Cube");
    remove_tool_menu_item("Generate Sphere");
}

void ShapeGenerator::_generate_cube_with_collision() {
    MeshInstance3D *cube = memnew(MeshInstance3D);
    cube->set_mesh(memnew(BoxMesh));
    cube->set_name("Cube");

    CollisionShape3D *collision = memnew(CollisionShape3D);
    collision->set_shape(memnew(BoxShape3D));
    cube->add_child(collision);
    collision->set_owner(get_editor_interface()->get_edited_scene_root());

    _add_to_scene(cube);
}

void ShapeGenerator::_generate_sphere_with_collision() {
    // Similar to cube, but with SphereMesh/SphereShape3D
}

void ShapeGenerator::_add_to_scene(Node *node) {
    Node *scene_root = get_editor_interface()->get_edited_scene_root();
    scene_root->add_child(node);
    node->set_owner(scene_root);
}
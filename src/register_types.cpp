#include <godot_cpp/core/class_db.hpp>
#include "./gen3D/shape_generator.h"

void initialize_shape_module(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
        ClassDB::register_class<ShapeGenerator>();
    }
}

void uninitialize_shape_module(ModuleInitializationLevel p_level) {
    // Cleanup if needed
}

extern "C" {
GDExtensionBool GDE_EXPORT shape_generator_init(
    GDExtensionInterfaceGetProcAddress p_get_proc_address,
    GDExtensionClassLibraryPtr p_library,
    GDExtensionInitialization *r_initialization
) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
    init_obj.register_initializer(initialize_shape_module);
    init_obj.register_terminator(uninitialize_shape_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_EDITOR);
    return init_obj.init();
}
}
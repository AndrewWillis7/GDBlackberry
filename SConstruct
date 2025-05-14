# SConstruct
env = Environment()

# Godot-CPP paths
env.Append(CPPPATH=["godot-cpp/include"])
env.Append(LIBPATH=["godot-cpp/bin"])
env.Append(CPPDEFINES=["GDEXTENSION_LIBRARY"])

env.Append(CPPPATH=[
    "godot-cpp/include",
    "godot-cpp/gdextension",
    "godot-cpp/include/core",
    "godot-cpp/include/gen"
])

# For MSVC
env.Append(CPPDEFINES=["WINDOWS_ENABLED", "TYPED_METHOD_BIND"])

# Compiler settings (adjust for your OS)
env["platform"] = "windows"
env["target"] = "editor"

# Source files
sources = [
    "src/gen3D/shape_generator.cpp",
    "src/register_types.cpp",
]

# Build the shared library
shared_lib = env.SharedLibrary(
    target="bin/GDBlackberry",  # Output .dll/.so/.dylib
    source=sources,
)

# Copy the output to the addons folder (optional)
env.Alias("install", shared_lib, "bin/GDBlackberry.dll")
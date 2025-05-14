# GDBlackberry
A new version of Godot that is streamlined to what I need

**BUILD**

In Terminal (Builds the Bindings): 
```PYTHON
cd godot-cpp
scons platform=windows target=editor generate_bindings=yes --jobs=4
```

In Terminal (Builds the Project):
```PYTHON
scons platform=windows target=editor -j4
```

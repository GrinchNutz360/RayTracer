# C++ Ray Tracer

A lightweight, extensible **CPU ray tracer** written in modern C++, using **SDL3** for window/output and **glm** for mathematical operations.  
The renderer features a minimal scene containing **spheres on an infinite plane**, supporting multiple physically-motivated material types and recursive ray scattering.

---

## 📘 Introduction

This project implements a classic path-tracing–style ray tracer from scratch using C++17.  
It is designed to be simple, readable, and ideal for learning the fundamentals of ray tracing while still supporting realistic lighting behavior.

The scene is placed in a clean framework, allowing you to experiment with shading, materials, geometry, or acceleration structures.

---

## ✨ Features

### 🎥 Core Rendering
- Recursive **ray tracing** for diffuse, reflective, refractive, and emissive interactions
- Configurable ray depth
- Anti-aliasing (supersampling)
- Gamma correction
- Infinite-plane ground surface
- Ray-sphere intersections

### 💡 Material System
Supports the following physically motivated materials:

- **Lambertian (Diffuse)**  
  Soft, matte scattering using cosine-weighted hemispherical distribution.

- **Metal**  
  Perfect mirror and fuzzy reflections.

- **Dielectric**  
  Full internal reflection, refraction, and Fresnel effects.

- **Emissive (Light Source)**  
  Simple light-emitting materials without shadow rays.

### 🛠️ Framework
- **SDL3** for window creation, framebuffer display, and timing
- **glm** for vector/matrix operations
- Multi-threading ready (if you want to expand)

---

## 🛠️ Installation

### **Prerequisites**

Make sure these dependencies are installed:

- C++17 (or newer) compiler  
- **CMake** (3.10+)  
- **SDL3** development libraries  
- **glm**

### **Build Instructions**

If you run it as it is now, you will see this:
<img width="799" height="641" alt="Screenshot 2025-12-11 145510" src="https://github.com/user-attachments/assets/37a587bc-01b7-413b-ab16-c0a2aea38813" />

Can change things in Scene, Materials, Camera, and Ray.
```bash
git clone https://github.com/GrinchNutz360/RayTracer.git
cd RayTracer
mkdir build && cd build
cmake ..
cmake --build .

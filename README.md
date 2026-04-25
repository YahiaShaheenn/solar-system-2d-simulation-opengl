# 2D Inner Solar System Simulation (OpenGL / C++)

# Overview

This project is a 2D animated simulation of the inner solar system, developed using C++ and OpenGL (GLUT). It visualizes the Sun along with Mercury, Venus, Earth, and Mars, where each planet moves along its orbital path with a speed proportional to its real-world orbital period.

The animation is controlled using `glutTimerFunc`, allowing real-time updates and interactive speed control via keyboard input.

---

# Objectives

* Simulate planetary motion using real astronomical proportions
* Implement smooth animation using GLUT timer functions
* Apply parametric equations for circular motion
* Avoid built-in rotation transformations (`glRotatef`) and compute motion manually

---

# Features

*  Sun-centered planetary system
*  Four planets with independent orbital speeds:

  * Mercury
  * Venus
  * Earth
  * Mars
*  Real-time animation using `glutTimerFunc()`
*  Keyboard-controlled simulation speed
*  Accurate circular motion using trigonometric functions
*  No use of `glRotatef` (manual position calculation)

---

# How It Works

Each planet's motion is based on angular velocity:

ω = 2π / T

Where:

* T = orbital period of the planet

The position of each planet is updated using:

x = r × cos(θ)
y = r × sin(θ)

* r = orbital radius
* θ = current angle (updated over time)

The animation loop is driven by:

glutTimerFunc(period, timerFunction, value);


This ensures smooth, time-based updates independent of frame rate.

---

# Controls

| Key   | Function                  |
| ----- | ------------------------- |
| `↑`   | Increase simulation speed |
| `↓`   | Decrease simulation speed |
| `ESC` | Exit program              |

---


# Technologies Used

* C++
* OpenGL
* GLUT / FreeGLUT
* Basic Physics (orbital motion)

---

# Preview

<img width="1918" height="828" alt="Screenshot 2026-04-25 121323" src="https://github.com/user-attachments/assets/ce3d9bab-b0ee-4e82-990e-5da58cd06c7c" />


---



# Learning Outcomes

* Implementing real-time animation using GLUT
* Understanding parametric motion in computer graphics
* Translating physical equations into visual simulations
* Managing animation timing without relying on built-in transformations

---

# Notes

* Orbital radii are scaled for visualization clarity (not real distances)
* Speeds are proportional to real orbital periods, not exact real-time values

---

# Authors
Yahia Ahmed Shaheen, Maya Ramy , Shaza Ahmed, Reem Khaled, and Merna Amr

Biomedical Engineering Students
Cairo University

Interested in Computer Graphics, Simulation, and Embedded Systems

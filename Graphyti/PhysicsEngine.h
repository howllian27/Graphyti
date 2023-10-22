// PhysicsEngine.h
#pragma once
#include "GameObject.h"

class PhysicsEngine {
public:
    PhysicsEngine();

    // Update the position and velocity of a game object based on physics
    void Update(GameObject& object, float deltaTime);

    // Setters for global physics properties
    void SetGravity(float gravity);
    void SetTimeScale(float scale);
    void SetWarpMatrix(float matrix[3][3]);
    void SetGravitationalField(float strength, float x, float y, float z);

private:
    float m_gravity;      // Global gravity value
    float m_timeScale;    // Speed up or slow down time
    float m_warpMatrix[3][3]; // Warp Matrix
    float m_gravitationalFieldStrength; // Gravitational Field Stength
    float m_gravitationalFieldPosition[3]; // Gravitational Field Stength 3D
};
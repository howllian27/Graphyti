// PhysicsEngine.cpp
#include "PhysicsEngine.h"
#include <cmath>
using namespace std;

PhysicsEngine::PhysicsEngine() : 
    m_gravity(-9.81f), 
    m_timeScale(1.0f),
    m_gravitationalFieldStrength(0.0f),
    m_gravitationalFieldPosition{ 0.0f, 0.0f, 0.0f },
    m_warpMatrix{ {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f} }
{}

void PhysicsEngine::SetGravitationalField(float strength, float x, float y, float z) {
    m_gravitationalFieldStrength = strength;
    m_gravitationalFieldPosition[0] = x;
    m_gravitationalFieldPosition[1] = y;
    m_gravitationalFieldPosition[2] = z;
}

void PhysicsEngine::Update(GameObject& object, float deltaTime) {
    float x, y, z, vx, vy, vz;
    object.GetPosition(x, y, z);
    object.GetVelocity(vx, vy, vz);

    // Apply gravity
    vy += m_gravity * deltaTime * m_timeScale;

    // Update position based on velocity
    x += vx * deltaTime * m_timeScale;
    y += vy * deltaTime * m_timeScale;
    z += vz * deltaTime * m_timeScale;

    object.SetPosition(x, y, z);
    object.SetVelocity(vx, vy, vz);

    float scaleX, scaleY, scaleZ;
    object.GetScale(scaleX, scaleY, scaleZ);

    // Apply scaling
    x *= scaleX;
    y *= scaleY;
    z *= scaleZ;

    // Apply warp matrix transformation
    float newX = m_warpMatrix[0][0] * x + m_warpMatrix[0][1] * y + m_warpMatrix[0][2] * z;
    float newY = m_warpMatrix[1][0] * x + m_warpMatrix[1][1] * y + m_warpMatrix[1][2] * z;
    float newZ = m_warpMatrix[2][0] * x + m_warpMatrix[2][1] * y + m_warpMatrix[2][2] * z;

    x = newX;
    y = newY;
    z = newZ;

    // Apply gravitational field bending
    float dx = x - m_gravitationalFieldPosition[0];
    float dy = y - m_gravitationalFieldPosition[1];
    float dz = z - m_gravitationalFieldPosition[2];
    float distance = sqrt(dx * dx + dy * dy + dz * dz);
    if (distance < m_gravitationalFieldStrength) {
        float bendFactor = m_gravitationalFieldStrength / distance;
        x += dx * bendFactor;
        y += dy * bendFactor;
        z += dz * bendFactor;
    }
}

void PhysicsEngine::SetGravity(float gravity) {
    m_gravity = gravity;
}

void PhysicsEngine::SetTimeScale(float scale) {
    m_timeScale = scale;
}

void PhysicsEngine::SetWarpMatrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m_warpMatrix[i][j] = matrix[i][j];
}


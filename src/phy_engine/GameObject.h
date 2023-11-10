// GameObject.h
#pragma once

class GameObject {
public:
    GameObject(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    // Position getters and setters
    void SetPosition(float x, float y, float z);
    void GetPosition(float& x, float& y, float& z) const;

    // Velocity getters and setters
    void SetVelocity(float x, float y, float z);
    void GetVelocity(float& x, float& y, float& z) const;

    // Scale getters and setters
    void SetScale(float x, float y, float z);
    void GetScale(float& x, float& y, float& z) const;

    // Polar coordinate getters and setters
    void SetPolarCoordinates(float radius, float theta, float phi);
    void GetPolarCoordinates(float& radius, float& theta, float& phi) const;

private:
    float m_x, m_y, m_z;       // Position
    float m_vx, m_vy, m_vz;   // Velocity
    float m_scaleX, m_scaleY, m_scaleZ; // Scaling
    float m_radius, m_theta, m_phi; // Polar Coordinate System
};
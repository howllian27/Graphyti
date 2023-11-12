// GameObject.cpp
#include "GameObject.h"

GameObject::GameObject(float x, float y, float z)
    : m_x(x), m_y(y), m_z(z), m_vx(0.0f), m_vy(0.0f), m_vz(0.0f) {}

void GameObject::SetPosition(float x, float y, float z) {
    m_x = x;
    m_y = y;
    m_z = z;
}

void GameObject::GetPosition(float& x, float& y, float& z) const {
    x = m_x;
    y = m_y;
    z = m_z;
}

void GameObject::SetVelocity(float x, float y, float z) {
    m_vx = x;
    m_vy = y;
    m_vz = z;
}

void GameObject::GetVelocity(float& x, float& y, float& z) const {
    x = m_vx;
    y = m_vy;
    z = m_vz;
}

void GameObject::SetScale(float x, float y, float z) {
    m_scaleX = x;
    m_scaleY = y;
    m_scaleZ = z;
}

void GameObject::GetScale(float& x, float& y, float& z) const {
    x = m_scaleX;
    y = m_scaleY;
    z = m_scaleZ;
}

void GameObject::SetPolarCoordinates(float radius, float theta, float phi) {
    m_radius = radius;
    m_theta = theta;
    m_phi = phi;
}

void GameObject::GetPolarCoordinates(float& radius, float& theta, float& phi) const {
    radius = m_radius;
    theta = m_theta;
    phi = m_phi;
}

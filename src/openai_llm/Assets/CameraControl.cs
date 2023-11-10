using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraControl : MonoBehaviour
{
    public float panSpeed = 20f;
    public float zoomSpeed = 1000f;

    void Update()
    {
        // Panning
        if (Input.GetKey(KeyCode.W))
            transform.Translate(Vector3.forward * panSpeed * Time.deltaTime);
        if (Input.GetKey(KeyCode.S))
            transform.Translate(Vector3.back * panSpeed * Time.deltaTime);
        if (Input.GetKey(KeyCode.A))
            transform.Translate(Vector3.left * panSpeed * Time.deltaTime);
        if (Input.GetKey(KeyCode.D))
            transform.Translate(Vector3.right * panSpeed * Time.deltaTime);

        // Zooming
        float zoom = Input.GetAxis("Mouse ScrollWheel");
        transform.Translate(Vector3.forward * zoom * zoomSpeed * Time.deltaTime);
    }
}

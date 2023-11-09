# Camera

OpenGL is not familiar with the concept of a camera, but we can simulate one by
moving all objects in the scene as we move. Which gives the illusion that we are
moving. 

## View space

The view space is all vertex coordinates as seen from the camera's perspective 
as the origin of the scene. The view matrix transforms all the world coordinates
into view coordinates that are relative to the camera's position and direction.

To define a camera, we need its: 

* _Position_ in world space
* _Direction_ it's looking at, a vector to the right and upwards from the camera

We're creating a coordinate system with 3 perpendicular unit axes with the 
camera's position as origin.

* _Camera position_ - is just a vector in world space. 

## Camera direction

Subtracting the camera position from the camera target vector gets you the 
direction you want. 

The _right_ vector represents the $x$-axis of the camera space. To get the right
vector, we use a trick of first specifying an _up_ vector that points upwards in
world space. Then we can take the cross product on the up vector and the 
direction vector to get the right vector. This works because the cross product 
is a vector perpendicular to both vectors. 

The _up_ axis is the positive $y$-axis of the camera. We already have the 
negative $z$-axis and positive $x$-axis. To get the positive $y$, we just take 
the cross product of these two.

This process is known as the _Gram-Schmidt process_ in linear algebra. With 
these camera vectors we can create the _look at_ matrix.

## Look at

If you define a coordinate space with three perpendicular axes, you can create a
matrix with those three axes plus a translation vector and you can transform any
vector to that coordinate space by multiplying with this matrix. This is what 
the look at matrix does. 

## Look around

To look around, we have to change the camera front vector based on mouse input.

### Euler angles

There are three values that can represent any rotation in 3D space. These are 
called the Euler angles, _pitch_, _yaw_, and _roll_.

We can get the camera direction's $x$ and $z$ axes from the yaw. 

```cpp
glm::vec3 direction;
direction.x = cos(glm::radians(yaw));
direction.z = sin(glm::radians(yaw));
```

We can get the camera direction's $y$ axis from the sine of the pitch .

```cpp
direction.y = sin(glm::radians(pitch));
```

However, the $x$ and $z$ sides are also influenced by the cosine of the pitch. 

```cpp
direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
direction.y = sin(glm::radians(pitch));
direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
```
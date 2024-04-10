#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex_coord;

out vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(pos, 1.0);
    float c = (tex_coord.x + tex_coord.y) / 2;
    color = vec3(c, c, c);
}
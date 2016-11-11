#version 330  //告诉编译器我们的目标GLSL编译器版本是3.3

layout (location = 0) in vec3 Position; // 绑定定点属性名和属性，方式二缓冲属性和shader属性对应映射

uniform mat4 gTransMat;

void main()
{
    gl_Position = gTransMat * vec4(Position, 1.0); // 为glVertexAttributePointer提供返回值
}
#version 330  //告诉编译器我们的目标GLSL编译器版本是3.3

layout (location = 0) in vec3 Position; // 绑定定点属性名和属性，方式二缓冲属性和shader属性对应映射

uniform mat4 gTransMat;

varying vec4 Color;

void main()
{
	vec3 grayr = vec3(0.4,0.4,0.1);
	vec3 grayg = vec3(0.3,0.5,0.2);
	vec3 grayb = vec3(0.2,0.2,0.6);
    gl_Position = gTransMat * vec4(Position, 1.0); // 为glVertexAttributePointer提供返回值
	float r = dot(Position, grayr);
	float g = dot(Position, grayg);
	float b = dot(Position, grayb);
	Color = vec4(clamp(Position,0.0,1.0), 1.0);
}
#version 330  //���߱��������ǵ�Ŀ��GLSL�������汾��3.3

layout (location = 0) in vec3 Position; // �󶨶��������������ԣ���ʽ���������Ժ�shader���Զ�Ӧӳ��

uniform mat4 gTransMat;

varying vec4 Color;

void main()
{
	vec3 grayr = vec3(0.4,0.4,0.1);
	vec3 grayg = vec3(0.3,0.5,0.2);
	vec3 grayb = vec3(0.2,0.2,0.6);
    gl_Position = gTransMat * vec4(Position, 1.0); // ΪglVertexAttributePointer�ṩ����ֵ
	float r = dot(Position, grayr);
	float g = dot(Position, grayg);
	float b = dot(Position, grayb);
	Color = vec4(clamp(Position,0.0,1.0), 1.0);
}
#version 330  //���߱��������ǵ�Ŀ��GLSL�������汾��3.3

layout (location = 0) in vec3 Position; // �󶨶��������������ԣ���ʽ���������Ժ�shader���Զ�Ӧӳ��

uniform mat4 gTransMat;

void main()
{
    gl_Position = gTransMat * vec4(Position, 1.0); // ΪglVertexAttributePointer�ṩ����ֵ
}
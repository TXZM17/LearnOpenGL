#version 330  //���߱��������ǵ�Ŀ��GLSL�������汾��3.3

out vec4 FragColor;  // Ƭ����ɫ���������ɫ����

uniform vec3 gColor;

// ��ɫ����Ψһ��ں���
void main()
{
    // ���������ɫֵ
    FragColor = vec4(gColor.x, gColor.y, gColor.z, 1.0);
}

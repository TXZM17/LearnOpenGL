#version 330  //���߱��������ǵ�Ŀ��GLSL�������汾��3.3

out vec4 FragColor;  // Ƭ����ɫ���������ɫ����

varying vec4 Color;

// ��ɫ����Ψһ��ں���
void main()
{
    // ���������ɫֵ
    FragColor = vec4(Color.x, Color.y, Color.z, 1.0);
}

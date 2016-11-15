#version 330  //告诉编译器我们的目标GLSL编译器版本是3.3

out vec4 FragColor;  // 片段着色器的输出颜色变量

varying vec4 Color;

// 着色器的唯一入口函数
void main()
{
    // 定义输出颜色值
    FragColor = vec4(Color.x, Color.y, Color.z, 1.0);
}

#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
            ///檔案不存在,會又很小聲的錯誤聲音
    PlaySound("07072060.wav",NULL,SND_SYNC);
    printf("PlaySound()之後\n");
}

#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()���e\n");
            ///�ɮפ��s�b,�|�S�ܤp�n�����~�n��
    PlaySound("07072060.wav",NULL,SND_SYNC);
    printf("PlaySound()����\n");
}

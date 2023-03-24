#ifndef PSPVAUDIO_H
#define PSPVAUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#define PSP_VAUDIO_VOLUME_MAX		0x8000

#define PSP_VAUDIO_SAMPLE_MAX		2048
#define PSP_VAUDIO_SAMPLE_MIN		256

#define PSP_VAUDIO_FORMAT_MONO		1
#define PSP_VAUDIO_FORMAT_STEREO	2

#define PSP_VAUDIO_EFFECT_OFF		0
#define PSP_VAUDIO_EFFECT_HEAVY		1
#define PSP_VAUDIO_EFFECT_POPS		2
#define PSP_VAUDIO_EFFECT_JAZZ		3
#define PSP_VAUDIO_EFFECT_UNIQUE	4
#define PSP_VAUDIO_EFFECT_MAX		5

#define PSP_VAUDIO_ALC_OFF			0
#define PSP_VAUDIO_ALC_MODE1		1
#define PSP_VAUDIO_ALC_MODE_MAX		2

int sceVaudioOutputBlocking(int volume, void *buffer);
int sceVaudioChReserve(int samplecount, int frequency, int format);
int sceVaudioChRelease(void);
int sceVaudioSetEffectType(int effect, int volume);
int sceVaudioSetAlcMode(int mode);

#ifdef __cplusplus
}
#endif

#endif /* PSPVAUDIO_H */

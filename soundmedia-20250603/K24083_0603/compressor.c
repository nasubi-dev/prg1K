#include "wave.h"

int main(void)
{
    MONO_PCM pcm0, pcm1;
    int n;
    double threshold, ratio, gain = 0.0;

    /* WAVEファイルからモノラルの音データを入力する */
    mono_wave_read(&pcm0, "sample03.wav");

    pcm1.fs = pcm0.fs;                            /* 標本化周波数 */
    pcm1.bits = pcm0.bits;                        /* 量子化精度 */
    pcm1.length = pcm0.length;                    /* 音データの長さ */
    pcm1.s = calloc(pcm1.length, sizeof(double)); /* メモリの確保 */

    threshold = 0.3; /* しきい値 */
    ratio = 0.1;     /* レシオ */

    /* ここで増幅率を計算する */
    gain = 1.0 / (threshold + ((threshold + 1.0) * ratio));

    for (n = 0; n < pcm1.length; n++)
    {
        pcm1.s[n] = pcm0.s[n];

        if (pcm0.s[n] > threshold)
        {
            pcm1.s[n] = threshold + (pcm0.s[n] - threshold) * ratio;
        }
        else if (pcm0.s[n] < -threshold)
        {
            pcm1.s[n] = -threshold + (pcm0.s[n] + threshold) * ratio;
        }
        else
        {
            /* しきい値以下の場合はそのまま */
            pcm1.s[n] = pcm0.s[n];
        }

        pcm1.s[n] *= gain; /* 振幅の増幅 */
    }

    /* WAVEファイルにモノラルの音データを出力する */
    mono_wave_write(&pcm1, "compressor.wav");

    free(pcm0.s); /* メモリの解放 */
    free(pcm1.s); /* メモリの解放 */

    return 0;
}

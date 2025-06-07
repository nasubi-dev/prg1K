#include "wave.h"

int main(void)
{
    MONO_PCM pcm0, pcm1;
    int n, m = 0;
    double d, depth, rate, t, tau, delta;

    /* WAVEファイルからモノラルの音データを入力する */
    mono_wave_read(&pcm0, "sample05.wav");

    pcm1.fs = pcm0.fs;                            /* 標本化周波数 */
    pcm1.bits = pcm0.bits;                        /* 量子化精度 */
    pcm1.length = pcm0.length;                    /* 音データの長さ */
    pcm1.s = calloc(pcm1.length, sizeof(double)); /* メモリの確保 */

    d = pcm1.fs * 0.002;     /* オフセット：標本化周波数 × 秒数 */
    depth = pcm1.fs * 0.002; /* 揺れの深さ：標本化周波数 × 秒数 */
    rate = 0.4;

    /* ビブラート */
    for (n = 0; n < pcm1.length; n++)
    {
        /* 円周率πには M_PI という定数マクロを用いよ */
        /* 標本化周波数Fsはpcm1.fsに対応 */
        tau = d + depth * sin(2 * M_PI * rate * n / pcm1.fs);
        t = (double)n + tau;
        m = (int)t;
        delta = t - m;
        if (m >= 0 && m + 1 < pcm1.length)
        {
            /* s0を線形補間してs1を計算 */
            pcm1.s[n] = delta * pcm0.s[m + 1] + (1 - delta) * pcm0.s[m];
        }
    }

    /* WAVEファイルにモノラルの音データを出力する */
    mono_wave_write(&pcm1, "vibrato.wav");

    free(pcm0.s); /* メモリの解放 */
    free(pcm1.s); /* メモリの解放 */

    return 0;
}

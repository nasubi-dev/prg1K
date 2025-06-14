#include "wave.h"

/* リバーブの効果を作るプログラム */
int main(void) {
    MONO_PCM pcm0, pcm1;
    int n, m, i, repeat;
    double a, d;

    /* WAVEファイルからモノラルの音データを入力する */
    mono_wave_read(&pcm0, "drum.wav");

    pcm1.fs = pcm0.fs;         /* 標本化周波数 */
    pcm1.bits = pcm0.bits;     /* 量子化精度 */
    pcm1.length = pcm0.length; /* 音データの長さ */
    pcm1.s = (double *)malloc(pcm1.length * sizeof(double)); /* メモリの確保 */

    /* 値は各自で調整すること（あえてイマイチな値に設定している） */
    a = 0.8; /* 減衰率 */
    d = 0.2 * pcm1.fs; /* 遅延サンプル数 = 遅延時間(秒) × 標本化周波数(Hz) */
    repeat = 2; /* 繰り返し回数 */

    /* プログラムを完成させよ */
    for (n = 0; n < pcm1.length; n++) {
    }

    /* WAVEファイルにモノラルの音データを出力する */
    mono_wave_write(&pcm1, "reverb.wav");

    free(pcm0.s); /* メモリの解放 */
    free(pcm1.s); /* メモリの解放 */

    return 0;
}

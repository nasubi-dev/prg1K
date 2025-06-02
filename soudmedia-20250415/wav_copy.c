#include "wave.h"

/* WAVを読み込み、中身をコピーしてWAVファイルとして書き出すプログラム */
int main(void) {
    /* 音データのための構造体 */
    MONO_PCM pcm0, pcm1; /* pcm0: コピー元、pcm1: コピー先 */
    int n;
    char out_filename[] = "./wav/wave_copy_out.wav"; /* 出力ファイル名 */

    /* WAVの読み込み */
    /* 構造体変数 pcm0 に必要な情報を格納する */
    mono_wave_read(&pcm0, "./sample_wave.wav"); /* 音データの入力 */

    /* コピー： pcm0 -> pcm1 */
    pcm1.fs = pcm0.fs;         /* 標本化周波数 */
    pcm1.bits = pcm0.bits;     /* 量子化精度 */
    pcm1.length = pcm0.length; /* 音データの長さ */

    /* 音データのコピー */
    pcm1.s = malloc(pcm1.length * sizeof(double)); /* 音データのメモリ確保 */
    for (n = 0; n < pcm1.length; n++) {
        pcm1.s[n] = pcm0.s[n]; /* コピー */
    }

    /* WAVの書き出し */
    mono_wave_write(&pcm1, out_filename); /* 音データの出力 */

    /* メモリの開放 */
    free(pcm0.s);
    free(pcm1.s);

    return 0;
}

#include "fAx8529.h"

inline int fAx8529(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8529.data[i][j] = bmats.A_17_31.data[i][j] - 16*bmats.A_17_32.data[i][j] + bmats.A_18_31.data[i][j] - 16*bmats.A_18_32.data[i][j] + bmats.A_19_31.data[i][j] - 16*bmats.A_19_32.data[i][j] + bmats.A_20_31.data[i][j] - 16*bmats.A_20_32.data[i][j] + bmats.A_21_31.data[i][j] - 16*bmats.A_21_32.data[i][j] + bmats.A_22_31.data[i][j] - 16*bmats.A_22_32.data[i][j] + bmats.A_23_31.data[i][j] - 16*bmats.A_23_32.data[i][j] + bmats.A_24_31.data[i][j] - 16*bmats.A_24_32.data[i][j] + bmats.A_25_31.data[i][j] - 16*bmats.A_25_32.data[i][j] + bmats.A_28_31.data[i][j] - 16*bmats.A_28_32.data[i][j] + bmats.A_29_31.data[i][j] - 16*bmats.A_29_32.data[i][j] + bmats.A_30_31.data[i][j] - 16*bmats.A_30_32.data[i][j] + bmats.A_31_31.data[i][j] - 16*bmats.A_31_32.data[i][j] - 17*bmats.A_32_32.data[i][j] + bmats.Ax600.data[i][j] + bmats.Ax604.data[i][j] + bmats.Ax612.data[i][j] + bmats.Ax615.data[i][j] + bmats.Ax618.data[i][j] + bmats.Ax621.data[i][j] + bmats.Ax624.data[i][j] + bmats.Ax630.data[i][j] + bmats.Ax633.data[i][j] + bmats.Ax636.data[i][j] + bmats.Ax639.data[i][j] + bmats.Ax664.data[i][j] + bmats.Ax667.data[i][j];
        }
    }
    return 0;
}

#include "fAx4010.h"

inline int fAx4010(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4010.data[i][j] = bmats.A_17_21.data[i][j] - 16*bmats.A_17_22.data[i][j] + bmats.A_18_21.data[i][j] - 16*bmats.A_18_22.data[i][j] + bmats.A_19_21.data[i][j] - 16*bmats.A_19_22.data[i][j] + bmats.A_20_21.data[i][j] - 16*bmats.A_20_22.data[i][j] + bmats.A_21_21.data[i][j] - 16*bmats.A_21_22.data[i][j] - 17*bmats.A_22_22.data[i][j] + bmats.A_23_21.data[i][j] - 16*bmats.A_23_22.data[i][j] + bmats.A_24_21.data[i][j] - 16*bmats.A_24_22.data[i][j] + bmats.A_25_21.data[i][j] - 16*bmats.A_25_22.data[i][j] + bmats.A_26_21.data[i][j] - 16*bmats.A_26_22.data[i][j] + bmats.A_27_21.data[i][j] - 16*bmats.A_27_22.data[i][j] + bmats.A_30_21.data[i][j] - 16*bmats.A_30_22.data[i][j] + bmats.A_31_21.data[i][j] - 16*bmats.A_31_22.data[i][j] + bmats.A_32_21.data[i][j] - 16*bmats.A_32_22.data[i][j] + bmats.Ax110.data[i][j] + bmats.Ax128.data[i][j] + bmats.Ax1635.data[i][j] + bmats.Ax3930.data[i][j] + bmats.Ax3934.data[i][j] + bmats.Ax3937.data[i][j] + bmats.Ax3940.data[i][j] + bmats.Ax3943.data[i][j] + bmats.Ax3946.data[i][j] + bmats.Ax3949.data[i][j] + bmats.Ax42.data[i][j] + bmats.Ax74.data[i][j] + bmats.Ax93.data[i][j];
        }
    }
    return 0;
}
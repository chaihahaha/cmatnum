#include "fAx4678.h"

inline int fAx4678(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4678.data[i][j] = bmats.A_17_1.data[i][j] - 16*bmats.A_17_2.data[i][j] + bmats.A_18_1.data[i][j] - 16*bmats.A_18_2.data[i][j] + bmats.A_19_1.data[i][j] - 16*bmats.A_19_2.data[i][j] + bmats.A_20_1.data[i][j] - 16*bmats.A_20_2.data[i][j] + bmats.A_21_1.data[i][j] - 16*bmats.A_21_2.data[i][j] + bmats.A_22_1.data[i][j] - 16*bmats.A_22_2.data[i][j] + bmats.A_23_1.data[i][j] - 16*bmats.A_23_2.data[i][j] + bmats.A_24_1.data[i][j] - 16*bmats.A_24_2.data[i][j] + bmats.A_25_1.data[i][j] - 16*bmats.A_25_2.data[i][j] + bmats.A_26_1.data[i][j] - 16*bmats.A_26_2.data[i][j] + bmats.A_27_1.data[i][j] - 16*bmats.A_27_2.data[i][j] + bmats.A_28_1.data[i][j] - 16*bmats.A_28_2.data[i][j] + bmats.A_29_1.data[i][j] - 16*bmats.A_29_2.data[i][j] + bmats.A_30_1.data[i][j] - 16*bmats.A_30_2.data[i][j] + bmats.A_31_1.data[i][j] - 16*bmats.A_31_2.data[i][j] + bmats.A_32_1.data[i][j] - 16*bmats.A_32_2.data[i][j] + bmats.Ax1763.data[i][j] + bmats.Ax2125.data[i][j] + bmats.Ax2633.data[i][j] + bmats.Ax2882.data[i][j] + bmats.Ax3108.data[i][j] + bmats.Ax3507.data[i][j] + bmats.Ax3720.data[i][j] + bmats.Ax3875.data[i][j] + bmats.Ax4081.data[i][j] + bmats.Ax4392.data[i][j] + bmats.Ax4527.data[i][j] + bmats.Ax4586.data[i][j] + bmats.Ax4670.data[i][j] + bmats.Ax4673.data[i][j] + bmats.Ax4676.data[i][j] + bmats.Ax643.data[i][j];
        }
    }
    return 0;
}

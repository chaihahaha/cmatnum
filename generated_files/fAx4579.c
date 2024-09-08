#include "fAx4579.h"

inline int fAx4579(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4579.data[i][j] = -16*bmats.A_18_19.data[i][j] + bmats.A_18_20.data[i][j] - 17*bmats.A_19_19.data[i][j] - 16*bmats.A_20_19.data[i][j] + bmats.A_20_20.data[i][j] - 16*bmats.A_21_19.data[i][j] + bmats.A_21_20.data[i][j] - 16*bmats.A_23_19.data[i][j] + bmats.A_23_20.data[i][j] - 16*bmats.A_24_19.data[i][j] + bmats.A_24_20.data[i][j] - 16*bmats.A_25_19.data[i][j] + bmats.A_25_20.data[i][j] - 16*bmats.A_26_19.data[i][j] + bmats.A_26_20.data[i][j] - 16*bmats.A_27_19.data[i][j] + bmats.A_27_20.data[i][j] - 16*bmats.A_28_19.data[i][j] + bmats.A_28_20.data[i][j] - 16*bmats.A_29_19.data[i][j] + bmats.A_29_20.data[i][j] - 16*bmats.A_30_19.data[i][j] + bmats.A_30_20.data[i][j] - 16*bmats.A_31_19.data[i][j] + bmats.A_31_20.data[i][j] - 16*bmats.A_32_19.data[i][j] + bmats.A_32_20.data[i][j] + bmats.Ax105.data[i][j] + bmats.Ax123.data[i][j] + bmats.Ax1569.data[i][j] + bmats.Ax161.data[i][j] + bmats.Ax176.data[i][j] + bmats.Ax187.data[i][j] + bmats.Ax2149.data[i][j] + bmats.Ax31.data[i][j] + bmats.Ax4351.data[i][j] + bmats.Ax4376.data[i][j] + bmats.Ax69.data[i][j] + bmats.Ax88.data[i][j] + bmats.Ax923.data[i][j];
        }
    }
    return 0;
}

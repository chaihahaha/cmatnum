#include "fAx4821.h"

inline int fAx4821(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4821.data[i][j] = -17*bmats.A_17_17.data[i][j] - 16*bmats.A_18_17.data[i][j] + bmats.A_18_18.data[i][j] - 16*bmats.A_19_17.data[i][j] + bmats.A_19_18.data[i][j] - 16*bmats.A_20_17.data[i][j] + bmats.A_20_18.data[i][j] - 16*bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] - 16*bmats.A_22_17.data[i][j] + bmats.A_22_18.data[i][j] - 16*bmats.A_23_17.data[i][j] + bmats.A_23_18.data[i][j] - 16*bmats.A_24_17.data[i][j] + bmats.A_24_18.data[i][j] - 16*bmats.A_26_17.data[i][j] + bmats.A_26_18.data[i][j] - 16*bmats.A_27_17.data[i][j] + bmats.A_27_18.data[i][j] - 16*bmats.A_28_17.data[i][j] + bmats.A_28_18.data[i][j] - 16*bmats.A_29_17.data[i][j] + bmats.A_29_18.data[i][j] - 16*bmats.A_31_17.data[i][j] + bmats.A_31_18.data[i][j] - 16*bmats.A_32_17.data[i][j] + bmats.A_32_18.data[i][j] + bmats.Ax100.data[i][j] + bmats.Ax155.data[i][j] + bmats.Ax158.data[i][j] + bmats.Ax164.data[i][j] + bmats.Ax171.data[i][j] + bmats.Ax182.data[i][j] + bmats.Ax194.data[i][j] + bmats.Ax20.data[i][j] + bmats.Ax2131.data[i][j] + bmats.Ax4652.data[i][j] + bmats.Ax64.data[i][j] + bmats.Ax673.data[i][j] + bmats.Ax85.data[i][j];
        }
    }
    return 0;
}
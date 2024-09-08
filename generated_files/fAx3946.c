#include "fAx3946.h"

inline int fAx3946(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3946.data[i][j] = bmats.A_19_17.data[i][j] + bmats.A_19_18.data[i][j] + bmats.A_19_19.data[i][j] + bmats.A_19_20.data[i][j] + bmats.A_19_23.data[i][j] + bmats.A_19_24.data[i][j] + bmats.A_19_25.data[i][j] + bmats.A_19_26.data[i][j] + bmats.A_19_27.data[i][j] + bmats.A_19_28.data[i][j] + bmats.A_19_29.data[i][j] + bmats.A_19_30.data[i][j] + bmats.A_19_31.data[i][j] + bmats.A_19_32.data[i][j];
        }
    }
    return 0;
}

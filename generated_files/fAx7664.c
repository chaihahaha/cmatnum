#include "fAx7664.h"

inline int fAx7664(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7664.data[i][j] = 2*bmats.A_20_18.data[i][j] + 2*bmats.A_20_19.data[i][j] - 15*bmats.A_20_20.data[i][j] + 2*bmats.A_20_22.data[i][j] + 2*bmats.A_20_23.data[i][j] + 2*bmats.A_20_24.data[i][j] + 2*bmats.A_20_25.data[i][j] + 2*bmats.A_20_26.data[i][j] + 2*bmats.A_20_27.data[i][j] + 2*bmats.A_20_28.data[i][j] + 2*bmats.A_20_29.data[i][j] + 2*bmats.A_20_30.data[i][j] + 2*bmats.A_20_31.data[i][j] + 2*bmats.A_20_32.data[i][j];
        }
    }
    return 0;
}
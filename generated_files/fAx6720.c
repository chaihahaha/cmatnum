#include "fAx6720.h"

inline int fAx6720(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6720.data[i][j] = 2*bmats.A_32_17.data[i][j] + 2*bmats.A_32_18.data[i][j] + 2*bmats.A_32_19.data[i][j] + 2*bmats.A_32_20.data[i][j] + 2*bmats.A_32_21.data[i][j] + 2*bmats.A_32_24.data[i][j] + 2*bmats.A_32_25.data[i][j] + 2*bmats.A_32_26.data[i][j] + 2*bmats.A_32_27.data[i][j] + 2*bmats.A_32_28.data[i][j] + 2*bmats.A_32_29.data[i][j] + 2*bmats.A_32_30.data[i][j] + 2*bmats.A_32_31.data[i][j] - 15*bmats.A_32_32.data[i][j];
        }
    }
    return 0;
}

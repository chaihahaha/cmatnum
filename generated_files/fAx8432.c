#include "fAx8432.h"

inline int fAx8432(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8432.data[i][j] = 2*bmats.A_24_17.data[i][j] + 2*bmats.A_24_18.data[i][j] + 2*bmats.A_24_19.data[i][j] + 2*bmats.A_24_20.data[i][j] + 2*bmats.A_24_21.data[i][j] + 2*bmats.A_24_22.data[i][j] + 2*bmats.A_24_23.data[i][j] - 15*bmats.A_24_24.data[i][j] + 2*bmats.A_24_25.data[i][j] + 2*bmats.A_24_26.data[i][j] + 2*bmats.A_24_27.data[i][j] + 2*bmats.A_24_30.data[i][j] + 2*bmats.A_24_31.data[i][j] + 2*bmats.A_24_32.data[i][j];
        }
    }
    return 0;
}

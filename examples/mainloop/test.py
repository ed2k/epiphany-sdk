from ctypes import *
ehal = CDLL('/home/linaro/tools/host/lib/libe-hal.so')

e_init = ehal.e_init
e_reset_system = ehal.e_reset_system
e_get_platform_info = ehal.e_get_platform_info
e_finalize = ehal.e_finalize;

e_init(b'/home/linaro/bsps/current/zed_E16G3_512mb.hdf');
e_reset_system();
plat = create_string_buffer(200);
e_get_platform_info(plat);
emem = create_string_buffer(200);
ehal.e_alloc(emem, 0, 0x1000000);



ehal.e_free(emem);
e_finalize();
#print(sizeof(ehal.e_platform_t))


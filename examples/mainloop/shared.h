#include <stdint.h>

#define ROW 4
#define COL 4


typedef struct
{
  char state;
} msg_dev2host_t;

typedef struct
{
  char state;
} msg_host2dev_t;

typedef struct
{
  uint32_t output_addr;
  uint32_t input_addr;
  uint32_t input_size;
  uint32_t output_size;
} ext_info_t;

typedef struct
{
  msg_host2dev_t msg_h2d[ROW][COL];
  msg_dev2host_t msg_d2h[ROW][COL];
  ext_info_t args[ROW][COL];
} msg_block_t;


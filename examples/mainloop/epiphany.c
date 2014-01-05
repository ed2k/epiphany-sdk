#include "e_lib.h"
#include "shared.h"

#define BUF_ADDRESS 0x8f000000
#define BANK1 0x2000
#define BANK2 0x4000

void replace() {
	for (int i;i<0x1000;i+=sizeof(uint32_t)) {
		*(uint32_t*)(BANK2+i) = *(uint32_t*)(BANK1+i);
	}
}

int main(void)
{
	  uint32_t row = e_group_config.core_row;
	  uint32_t col = e_group_config.core_col;
	  volatile msg_block_t *msg = (msg_block_t *)BUF_ADDRESS;
	  volatile msg_host2dev_t * ph2d = &msg->msg_h2d[row][col];
	  volatile msg_dev2host_t * pd2h = &msg->msg_d2h[row][col];
	  volatile ext_info_t *pargs = &msg->args[row][col];
	  volatile ext_info_t *p;

	while (1)
	{

		while (ph2d->state != 'g') {

		}
		pd2h->state = 'g';
		e_dma_copy((char *)(BANK1), (void*)(pargs->input_addr), pargs->input_size);

		//__asm__ __volatile__ ("trap 4");
		replace(0);
		e_dma_copy((char *)(pargs->output_addr), (void*)(BANK2), pargs->output_size);
		pd2h->state = 's';
	}

	return 0;
}

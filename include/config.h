#ifndef CONFIG_H
#define CONFIG_H

/*
 *  Author: Hyam
 *  Date: 2023/03/17
 *  Description: 對整個udm-cache架構的變數定義集合
 */

typedef enum { READ, WRITE, DISCARD } operate;
typedef enum { PROMOTION, DEMOTION, WRITEBACK } mg_type;

/* udm-cache setting */
#define CBLOCK_SHIFT 15
#define CACHE_BLOCK_SIZE (1 << CBLOCK_SHIFT)  // 32KB
#define CACHE_BLOCK_NUMBER (1 << 15)          // 32K*32KB=1GB(SSD)
#define BUCKETS_NUMBER (CACHE_BLOCK_NUMBER)   // roundup_pow_of_two
#define PAGE_SHIFT 12
#define MOD_PAGE_PER_CBLOCK_SHIFT 0b111  // mod 8
#define PAGE_SIZE (1 << PAGE_SHIFT)      // 4KB
#define MAX_PATH_SIZE (1 << 5)           // full_path_name length
#define WRITEBACK_DELAY 500000000        // ns (in dm-cache is 500ms)
#define MIGRATION_DELAY 100000000        // ns (100ms)
#define MAX_WORKQUEUE_SIZE (CACHE_BLOCK_NUMBER >> 1)

/* share memory */
#define SHM_CACHE_NAME "/udm_cache"

/* spdk setting */
#define NVME_ADDR "0000:04:00.0"
#define IODEPTH 32

/* may increase hit ratio */
#define unlikely(x) __builtin_expect(!!(x), 0)

/* instead of a/b*/
#define safe_div(a, b) ((b != 0) ? ((double)(a) / (double)(b)) : 0.0)

#endif

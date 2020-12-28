#ifndef __SUPER_CUT_H__
#define __SUPER_CUT_H__


#include "libavutil/avstring.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#include "libavformat/avio_internal.h"
#include "libavformat/internal.h"
#include "libavformat/url.h"
#include "libavformat/version.h"


void super_cut_hls_write_playlist_version(AVIOContext *out, int version);
void super_cut_hls_write_audio_rendition(AVIOContext *out, char *agroup,
                                         char *filename, int name_id, int is_default);
void super_cut_hls_write_stream_info(AVStream *st, AVIOContext *out,
                                     int bandwidth, char *filename, char *agroup);
void super_cut_hls_write_playlist_header(AVIOContext *out, int version, int allowcache,
                                  int target_duration, int64_t sequence,
                                         uint32_t playlist_type) ;
void super_cut_hls_write_init_file(AVIOContext *out, char *filename,
                                   int byterange_mode, int64_t size, int64_t pos);
int super_cut_hls_write_file_entry(AVIOContext *out, int insert_discont,
                             int byterange_mode,
                             double duration, int round_duration,
                             int64_t size, int64_t pos, //Used only if HLS_SINGLE_FILE flag is set
                             char *baseurl, //Ignored if NULL
                                   char *filename, double *prog_date_time);
void super_cut_hls_write_end_list (AVIOContext *out);
static int super_cut_hls_open(URLContext *h, const char *uri, int flags);

#endif

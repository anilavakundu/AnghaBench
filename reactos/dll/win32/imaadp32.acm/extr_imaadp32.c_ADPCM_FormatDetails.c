#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int wFormatTag; int nChannels; int nSamplesPerSec; int wBitsPerSample; int nBlockAlign; int nAvgBytesPerSec; } ;
struct TYPE_8__ {int nChannels; int rate; int nBits; } ;
struct TYPE_7__ {int dwFormatTag; size_t dwFormatIndex; scalar_t__* szFormat; int /*<<< orphan*/  fdwSupport; TYPE_4__* pwfx; } ;
typedef  TYPE_1__* PACMFORMATDETAILSW ;
typedef  int /*<<< orphan*/  LRESULT ;
typedef  int /*<<< orphan*/  IMAADPCMWAVEFORMAT ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  ACMDRIVERDETAILS_SUPPORTF_CODEC ; 
 int /*<<< orphan*/  ACMERR_NOTPOSSIBLE ; 
#define  ACM_FORMATDETAILSF_FORMAT 131 
#define  ACM_FORMATDETAILSF_INDEX 130 
 TYPE_2__* ADPCM_Formats ; 
 int ADPCM_GetFormatIndex (TYPE_4__*) ; 
 size_t ARRAY_SIZE (TYPE_2__*) ; 
 int /*<<< orphan*/  MMSYSERR_INVALPARAM ; 
 int /*<<< orphan*/  MMSYSERR_NOERROR ; 
 int /*<<< orphan*/  MMSYSERR_NOTSUPPORTED ; 
 TYPE_2__* PCM_Formats ; 
 int /*<<< orphan*/  WARN (char*,int) ; 
#define  WAVE_FORMAT_IMA_ADPCM 129 
#define  WAVE_FORMAT_PCM 128 
 int /*<<< orphan*/  init_wfx_ima_adpcm (int /*<<< orphan*/ *) ; 

__attribute__((used)) static	LRESULT	ADPCM_FormatDetails(PACMFORMATDETAILSW afd, DWORD dwQuery)
{
    switch (dwQuery)
    {
    case ACM_FORMATDETAILSF_FORMAT:
	if (ADPCM_GetFormatIndex(afd->pwfx) == 0xFFFFFFFF) return ACMERR_NOTPOSSIBLE;
	break;
    case ACM_FORMATDETAILSF_INDEX:
	afd->pwfx->wFormatTag = afd->dwFormatTag;
	switch (afd->dwFormatTag)
        {
	case WAVE_FORMAT_PCM:
	    if (afd->dwFormatIndex >= ARRAY_SIZE(PCM_Formats)) return ACMERR_NOTPOSSIBLE;
	    afd->pwfx->nChannels = PCM_Formats[afd->dwFormatIndex].nChannels;
	    afd->pwfx->nSamplesPerSec = PCM_Formats[afd->dwFormatIndex].rate;
	    afd->pwfx->wBitsPerSample = PCM_Formats[afd->dwFormatIndex].nBits;
	    /* native MSACM uses a PCMWAVEFORMAT structure, so cbSize is not accessible
	     * afd->pwfx->cbSize = 0;
	     */
	    afd->pwfx->nBlockAlign =
		(afd->pwfx->nChannels * afd->pwfx->wBitsPerSample) / 8;
	    afd->pwfx->nAvgBytesPerSec =
		afd->pwfx->nSamplesPerSec * afd->pwfx->nBlockAlign;
	    break;
	case WAVE_FORMAT_IMA_ADPCM:
	    if (afd->dwFormatIndex >= ARRAY_SIZE(ADPCM_Formats)) return ACMERR_NOTPOSSIBLE;
	    afd->pwfx->nChannels = ADPCM_Formats[afd->dwFormatIndex].nChannels;
	    afd->pwfx->nSamplesPerSec = ADPCM_Formats[afd->dwFormatIndex].rate;
	    afd->pwfx->wBitsPerSample = ADPCM_Formats[afd->dwFormatIndex].nBits;
	    init_wfx_ima_adpcm((IMAADPCMWAVEFORMAT *)afd->pwfx);
	    break;
	default:
            WARN("Unsupported tag %08x\n", afd->dwFormatTag);
	    return MMSYSERR_INVALPARAM;
	}
	break;
    default:
	WARN("Unsupported query %08x\n", dwQuery);
	return MMSYSERR_NOTSUPPORTED;
    }
    afd->fdwSupport = ACMDRIVERDETAILS_SUPPORTF_CODEC;
    afd->szFormat[0] = 0; /* let MSACM format this for us... */

    return MMSYSERR_NOERROR;
}
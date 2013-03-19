#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php5/main/php.h>
#include <php5/main/php_main.h>
#include <php5/main/php_ini.h>
#include <php5/ext/standard/info.h>
#include <proc/procps.h>
#include <proc/sysinfo.h>
#include <proc/readproc.h>
#include <proc/version.h>
#include "php_procps.h"

int le_procps;

static zend_function_entry procps_functions[] = {
	ZEND_FE(readproctab, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry procps_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_PROCPS_EXTNAME,
    procps_functions,
    ZEND_MINIT(procps),
    ZEND_MSHUTDOWN(procps),
    ZEND_RINIT(procps),
    NULL,
	ZEND_MINFO(procps),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PROCPS_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

static void php_procps_dtor(zend_rsrc_list_entry *resource TSRMLS_DC)
{

}

ZEND_RINIT_FUNCTION(procps)
{
	return SUCCESS;
}

ZEND_MINIT_FUNCTION(procps)
{
	le_procps = zend_register_list_destructors_ex(php_procps_dtor, NULL, PHP_PROCPS_RES_NAME, module_number);

	zend_constant constantPROC_FILLMEM;
	constantPROC_FILLMEM.value.type = IS_LONG;
	constantPROC_FILLMEM.value.value.lval = 1;
	constantPROC_FILLMEM.flags = CONST_CS;
	constantPROC_FILLMEM.name = zend_strndup("PROC_FILLMEM", 12);
	constantPROC_FILLMEM.name_len = 13;
	constantPROC_FILLMEM.module_number = module_number;
	zend_register_constant(&constantPROC_FILLMEM TSRMLS_CC);

	zend_constant constantPROC_FILLCOM;
	constantPROC_FILLCOM.value.type = IS_LONG;
	constantPROC_FILLCOM.value.value.lval = 2;
	constantPROC_FILLCOM.flags = CONST_CS;
	constantPROC_FILLCOM.name = zend_strndup("PROC_FILLCOM", 12);
	constantPROC_FILLCOM.name_len = 13;
	constantPROC_FILLCOM.module_number = module_number;
	zend_register_constant(&constantPROC_FILLCOM TSRMLS_CC);

	zend_constant constantPROC_FILLENV;
	constantPROC_FILLENV.value.type = IS_LONG;
	constantPROC_FILLENV.value.value.lval = 4;
	constantPROC_FILLENV.flags = CONST_CS;
	constantPROC_FILLENV.name = zend_strndup("PROC_FILLENV", 12);
	constantPROC_FILLENV.name_len = 13;
	constantPROC_FILLENV.module_number = module_number;
	zend_register_constant(&constantPROC_FILLENV TSRMLS_CC);

	zend_constant constantPROC_FILLUSR;
	constantPROC_FILLUSR.value.type = IS_LONG;
	constantPROC_FILLUSR.value.value.lval = 8;
	constantPROC_FILLUSR.flags = CONST_CS;
	constantPROC_FILLUSR.name = zend_strndup("PROC_FILLUSR", 12);
	constantPROC_FILLUSR.name_len = 13;
	constantPROC_FILLUSR.module_number = module_number;
	zend_register_constant(&constantPROC_FILLUSR TSRMLS_CC);

	zend_constant constantPROC_FILLGRP;
	constantPROC_FILLGRP.value.type = IS_LONG;
	constantPROC_FILLGRP.value.value.lval = 16;
	constantPROC_FILLGRP.flags = CONST_CS;
	constantPROC_FILLGRP.name = zend_strndup("PROC_FILLGRP", 12);
	constantPROC_FILLGRP.name_len = 13;
	constantPROC_FILLGRP.module_number = module_number;
	zend_register_constant(&constantPROC_FILLGRP TSRMLS_CC);

	zend_constant constantPROC_FILLSTATUS;
	constantPROC_FILLSTATUS.value.type = IS_LONG;
	constantPROC_FILLSTATUS.value.value.lval = 32;
	constantPROC_FILLSTATUS.flags = CONST_CS;
	constantPROC_FILLSTATUS.name = zend_strndup("PROC_FILLSTATUS", 15);
	constantPROC_FILLSTATUS.name_len = 16;
	constantPROC_FILLSTATUS.module_number = module_number;
	zend_register_constant(&constantPROC_FILLSTATUS TSRMLS_CC);

	zend_constant constantPROC_FILLSTAT;
	constantPROC_FILLSTAT.value.type = IS_LONG;
	constantPROC_FILLSTAT.value.value.lval = 64;
	constantPROC_FILLSTAT.flags = CONST_CS;
	constantPROC_FILLSTAT.name = zend_strndup("PROC_FILLSTAT", 13);
	constantPROC_FILLSTAT.name_len = 14;
	constantPROC_FILLSTAT.module_number = module_number;
	zend_register_constant(&constantPROC_FILLSTAT TSRMLS_CC);

	zend_constant constantPROC_FILLWCHAN;
	constantPROC_FILLWCHAN.value.type = IS_LONG;
	constantPROC_FILLWCHAN.value.value.lval = 128;
	constantPROC_FILLWCHAN.flags = CONST_CS;
	constantPROC_FILLWCHAN.name = zend_strndup("PROC_FILLWCHAN", 14);
	constantPROC_FILLWCHAN.name_len = 15;
	constantPROC_FILLWCHAN.module_number = module_number;
	zend_register_constant(&constantPROC_FILLWCHAN TSRMLS_CC);

	zend_constant constantPROC_FILLARG;
	constantPROC_FILLARG.value.type = IS_LONG;
	constantPROC_FILLARG.value.value.lval = 256;
	constantPROC_FILLARG.flags = CONST_CS;
	constantPROC_FILLARG.name = zend_strndup("PROC_FILLARG", 12);
	constantPROC_FILLARG.name_len = 13;
	constantPROC_FILLARG.module_number = module_number;
	zend_register_constant(&constantPROC_FILLARG TSRMLS_CC);

	zend_constant constantPROC_FILLCGROUP;
	constantPROC_FILLCGROUP.value.type = IS_LONG;
	constantPROC_FILLCGROUP.value.value.lval = 512;
	constantPROC_FILLCGROUP.flags = CONST_CS;
	constantPROC_FILLCGROUP.name = zend_strndup("PROC_FILLCGROUP", 15);
	constantPROC_FILLCGROUP.name_len = 16;
	constantPROC_FILLCGROUP.module_number = module_number;
	zend_register_constant(&constantPROC_FILLCGROUP TSRMLS_CC);

	zend_constant constantPROC_FILLSUPGRP;
	constantPROC_FILLSUPGRP.value.type = IS_LONG;
	constantPROC_FILLSUPGRP.value.value.lval = 1024;
	constantPROC_FILLSUPGRP.flags = CONST_CS;
	constantPROC_FILLSUPGRP.name = zend_strndup("PROC_FILLSUPGRP", 15);
	constantPROC_FILLSUPGRP.name_len = 16;
	constantPROC_FILLSUPGRP.module_number = module_number;
	zend_register_constant(&constantPROC_FILLSUPGRP TSRMLS_CC);

	zend_constant constantPROC_FILLOOM;
	constantPROC_FILLOOM.value.type = IS_LONG;
	constantPROC_FILLOOM.value.value.lval = 2048;
	constantPROC_FILLOOM.flags = CONST_CS;
	constantPROC_FILLOOM.name = zend_strndup("PROC_FILLOOM", 12);
	constantPROC_FILLOOM.name_len = 13;
	constantPROC_FILLOOM.module_number = module_number;
	zend_register_constant(&constantPROC_FILLOOM TSRMLS_CC);

	return SUCCESS;
}

ZEND_MINFO_FUNCTION(procps)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "procps module", "enabled");
	php_info_print_table_row(2, "procps version", "0.1 beta");
	php_info_print_table_end();
}

ZEND_MSHUTDOWN_FUNCTION(procps)
{
	UNREGISTER_INI_ENTRIES();

	return SUCCESS;
}

#ifdef COMPILE_DL_PROCPS
ZEND_GET_MODULE(procps)
#endif

ZEND_FUNCTION(readproctab)
{
	long options = 0;
	proc_t **proctab;
	proc_t *tmpproc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &options) == FAILURE) {
		RETURN_FALSE;
	}

	proctab = readproctab(options);

	array_init(return_value);

	for(; *proctab; proctab++) {
		tmpproc = *proctab;
		if (tmpproc->cmdline != NULL) {
			zval *subarray;
			ALLOC_INIT_ZVAL(subarray);
			array_init(subarray);

			if (options & PROC_FILLCOM) {
				add_assoc_string(subarray, "cmdline", *tmpproc->cmdline, 1);
				add_assoc_long(subarray, "drs", tmpproc->drs);
				add_assoc_long(subarray, "egit", tmpproc->egid);
				add_assoc_long(subarray, "euid", tmpproc->euid);
				add_assoc_long(subarray, "resident", tmpproc->resident);
				add_assoc_long(subarray, "share", tmpproc->share);
				add_assoc_long(subarray, "size", tmpproc->size);
				add_assoc_long(subarray, "tgid", tmpproc->tgid);
				add_assoc_long(subarray, "tid", tmpproc->tid);
				add_assoc_long(subarray, "trs", tmpproc->trs);
			}

			if (options & PROC_FILLUSR) {
				add_assoc_string(subarray, "euser", tmpproc->euser, 1);
			}

			if (options & PROC_FILLGRP) {
				add_assoc_string(subarray, "egroup", tmpproc->egroup, 1);
			}

			if (options & PROC_FILLSTATUS) {
				add_assoc_string(subarray, "_sigpnd", tmpproc->_sigpnd, 1);
				add_assoc_string(subarray, "blocked", tmpproc->blocked, 1);
				add_assoc_string(subarray, "cmd", tmpproc->cmd, 1);
				add_assoc_long(subarray, "fgid", tmpproc->fgid);
				add_assoc_string(subarray, "fgroup", tmpproc->fgroup, 1);
				add_assoc_long(subarray, "fuid", tmpproc->fuid);
				add_assoc_string(subarray, "fuser", tmpproc->fuser, 1);
				add_assoc_long(subarray, "nlwp", tmpproc->nlwp);
				add_assoc_long(subarray, "ppid", tmpproc->ppid);
				add_assoc_long(subarray, "rgid", tmpproc->rgid);
				add_assoc_string(subarray, "rgroup", tmpproc->rgroup, 1);
				add_assoc_long(subarray, "ruid", tmpproc->ruid);
				add_assoc_string(subarray, "ruser", tmpproc->ruser, 1);
				add_assoc_string(subarray, "sgroup", tmpproc->sgroup, 1);
				add_assoc_string(subarray, "sigcatch", tmpproc->sigcatch, 1);
				add_assoc_long(subarray, "sgid", tmpproc->sgid);
				add_assoc_string(subarray, "sigignore", tmpproc->sigignore, 1);
				add_assoc_string(subarray, "signal", tmpproc->signal, 1);
				add_assoc_string(subarray, "state", &tmpproc->state, 1);
				add_assoc_long(subarray, "suid", tmpproc->suid);
				add_assoc_string(subarray, "suser", tmpproc->suser, 1);
				add_assoc_long(subarray, "vm_data", tmpproc->vm_data);
				add_assoc_long(subarray, "vm_exe", tmpproc->vm_exe);
				add_assoc_long(subarray, "vm_lib", tmpproc->vm_lib);
				add_assoc_long(subarray, "vm_lock", tmpproc->vm_lock);
				add_assoc_long(subarray, "vm_rss", tmpproc->vm_rss);
				add_assoc_long(subarray, "vm_size", tmpproc->vm_size);
				add_assoc_long(subarray, "vm_stack", tmpproc->vm_stack);
				//add_assoc_long(subarray, "vm_swap", tmpproc->vm_swap);
			}

			if (options & PROC_FILLSTAT) {
				add_assoc_long(subarray, "exit_signal", tmpproc->exit_signal);
				add_assoc_long(subarray, "flags", tmpproc->flags);
				add_assoc_long(subarray, "min_flt", tmpproc->min_flt);
				add_assoc_long(subarray, "nice", tmpproc->nice);
				add_assoc_long(subarray, "pgrp", tmpproc->pgrp);
				add_assoc_long(subarray, "priority", tmpproc->priority);
				add_assoc_long(subarray, "rss", tmpproc->rss);
				add_assoc_long(subarray, "rss_rlim", tmpproc->rss_rlim);
				add_assoc_long(subarray, "session", tmpproc->session);
				add_assoc_long(subarray, "start_code", tmpproc->start_code);
				add_assoc_long(subarray, "starttime", tmpproc->start_time);
				add_assoc_long(subarray, "stime", tmpproc->stime);
				add_assoc_long(subarray, "tpgid", tmpproc->tpgid);
				add_assoc_long(subarray, "tty", tmpproc->tty);
				add_assoc_long(subarray, "utime", tmpproc->utime);
				add_assoc_long(subarray, "vsize", tmpproc->vsize);
				add_assoc_long(subarray, "wchan", tmpproc->wchan);
			}

			if (options & PROC_FILLWCHAN) {
				add_assoc_long(subarray, "end_code", tmpproc->end_code);
			}

			if (options & PROC_FILLARG) {

			}

			if (options & PROC_FILLCGROUP) {

			}

			if (options & PROC_FILLSUPGRP) {

			}

			if (options && PROC_FILLOOM) {
				add_assoc_long(subarray, "start_stack", tmpproc->start_stack);
			}

			//*
			//add_assoc_string(subarray, "cgroup", *tmpproc->cgroup, 1);
			//add_assoc_string(subarray, "environ", *tmpproc->environ, 1);
			add_assoc_string(subarray, "pad_1", &tmpproc->pad_1, 1);
			add_assoc_string(subarray, "pad_2", &tmpproc->pad_2, 1);
			add_assoc_string(subarray, "pad_3", &tmpproc->pad_3, 1);
			//add_assoc_string(subarray, "supgid", &tmpproc->supgid, 1);
			//add_assoc_string(subarray, "supgrp", &tmpproc->supgrp, 1);
			add_assoc_long(subarray, "sched", tmpproc->sched);
			add_assoc_long(subarray, "rtprio", tmpproc->rtprio);
			add_assoc_long(subarray, "processor", tmpproc->processor);
			add_assoc_long(subarray, "pcpu", tmpproc->pcpu);
			//add_assoc_long(subarray, "min_delta", tmpproc->min_delta);
			add_assoc_long(subarray, "maj_flt", tmpproc->maj_flt);
			//add_assoc_long(subarray, "maj_delta", tmpproc->maj_delta);
			add_assoc_long(subarray, "lrs", tmpproc->lrs);
			add_assoc_long(subarray, "kstk_esp", tmpproc->kstk_esp);
			add_assoc_long(subarray, "kstk_eip", tmpproc->kstk_eip);
			add_assoc_long(subarray, "dt", tmpproc->dt);
			add_assoc_long(subarray, "cutime", tmpproc->cutime);
			add_assoc_long(subarray, "cstime", tmpproc->cstime);
			add_assoc_long(subarray, "cmin_flt", tmpproc->cmin_flt);
			add_assoc_long(subarray, "cmaj_flt", tmpproc->cmaj_flt);
			add_assoc_long(subarray, "alarm", tmpproc->alarm);
			//*/
			add_next_index_zval(return_value, subarray);

			//zval_ptr_dtor(&subarray);
		}
		freeproc(tmpproc);
	}

	freeproc(*proctab);
}

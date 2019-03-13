#include "processflow.h"


void processflow::writeCloneEvent(Context* cxt, sinsp_evt* ev) {
    sinsp_threadinfo* ti = ev->get_thread_info();
    bool created = false;
    Process* proc = process::getProcess(cxt, ev, ActionType::CREATED, created);
    cxt->procFlow.type =  CLONE;
    cxt->procFlow.ts = ev->get_ts();
    cxt->procFlow.procOID.hpid = proc->oid.hpid;
    cxt->procFlow.procOID.createTS = proc->oid.createTS;
    cxt->procFlow.tid = ti->m_tid;
    cxt->procFlow.ret = utils::getSyscallResult(ev);
    cxt->flow.rec.set_ProcessFlow(cxt->procFlow);
    cxt->numRecs++;
    cxt->dfw->write(cxt->flow);  
}

void processflow::writeExitEvent(Context* cxt, sinsp_evt* ev) {
    sinsp_threadinfo* ti = ev->get_thread_info();
    bool created = false;
    Process* proc = process::getProcess(cxt, ev, ActionType::REUP, created);
    cxt->procFlow.type =  EXIT;
    cxt->procFlow.ts = ev->get_ts();
    cxt->procFlow.procOID.hpid = proc->oid.hpid;
    cxt->procFlow.procOID.createTS = proc->oid.createTS;
    cxt->procFlow.tid = ti->m_tid;
    cxt->procFlow.ret = utils::getSyscallResult(ev);
    cxt->flow.rec.set_ProcessFlow(cxt->procFlow);
    cxt->numRecs++;
    cxt->dfw->write(cxt->flow);
    // delete the process from the proc table after an exit
    cxt->procs.erase(&proc->oid);
    delete proc; 

}

void processflow::writeExecEvent(Context* cxt, sinsp_evt* ev) {
    sinsp_threadinfo* ti = ev->get_thread_info();
    bool created = false;
    Process* proc = process::getProcess(cxt, ev, ActionType::CREATED, created);
   /* if(!created) {
      cout << "Exec on an existing process!" << endl;
    }*/
    process::updateProcess(cxt, proc, ev, ActionType::MODIFIED);
    process::writeProcess(cxt, proc);

    cxt->procFlow.type =  EXEC;
    cxt->procFlow.ts = ev->get_ts();
    cxt->procFlow.procOID.hpid = proc->oid.hpid;
    cxt->procFlow.procOID.createTS = proc->oid.createTS;
    cxt->procFlow.tid = ti->m_tid;
    cxt->procFlow.ret = utils::getSyscallResult(ev);
    cxt->flow.rec.set_ProcessFlow(cxt->procFlow);
    cxt->numRecs++;
    cxt->dfw->write(cxt->flow);  
}

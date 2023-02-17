#ifndef __AVSC_SYSFLOW2
#define __AVSC_SYSFLOW2
#include <string>
extern const std::string AVSC_SF = "{\n  \"type\" : \"record\",\n  \"name\" : \"SysFlow\",\n  \"namespace\" : \"sysflow\",\n  \"fields\" : [ {\n    \"name\" : \"rec\",\n    \"type\" : [ {\n      \"type\" : \"record\",\n      \"name\" : \"SFHeader\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"version\",\n        \"type\" : \"long\",\n        \"default\" : 2\n      }, {\n        \"name\" : \"exporter\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"ip\",\n        \"type\" : \"string\",\n        \"default\" : \"NA\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"Container\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"id\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"name\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"image\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"imageid\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"imagerepo\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"mountsource\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"mountdest\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"mountmode\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"mountpropagation\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"hostport\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"containerport\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"type\",\n        \"type\" : {\n          \"type\" : \"enum\",\n          \"name\" : \"ContainerType\",\n          \"namespace\" : \"sysflow.type\",\n          \"symbols\" : [ \"CT_DOCKER\", \"CT_LXC\", \"CT_LIBVIRT_LXC\", \"CT_MESOS\", \"CT_RKT\", \"CT_CUSTOM\", \"CT_CRI\", \"CT_CONTAINERD\", \"CT_CRIO\", \"CT_BPM\" ]\n        }\n      }, {\n        \"name\" : \"privileged\",\n        \"type\" : \"boolean\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"Process\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"state\",\n        \"type\" : {\n          \"type\" : \"enum\",\n          \"name\" : \"SFObjectState\",\n          \"namespace\" : \"sysflow.type\",\n          \"symbols\" : [ \"CREATED\", \"MODIFIED\", \"REUP\" ]\n        }\n      }, {\n        \"name\" : \"oid\",\n        \"type\" : {\n          \"type\" : \"record\",\n          \"name\" : \"OID\",\n          \"namespace\" : \"sysflow.type\",\n          \"fields\" : [ {\n            \"name\" : \"createTS\",\n            \"type\" : \"long\"\n          }, {\n            \"name\" : \"hpid\",\n            \"type\" : \"long\"\n          } ]\n        }\n      }, {\n        \"name\" : \"poid\",\n        \"type\" : [ \"null\", \"sysflow.type.OID\" ]\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"exe\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"exeArgs\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"uid\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"userName\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"gid\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"groupName\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"tty\",\n        \"type\" : \"boolean\"\n      }, {\n        \"name\" : \"containerId\",\n        \"type\" : [ \"null\", \"string\" ]\n      }, {\n        \"name\" : \"entry\",\n        \"type\" : \"boolean\",\n        \"default\" : false\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"File\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"state\",\n        \"type\" : \"sysflow.type.SFObjectState\"\n      }, {\n        \"name\" : \"oid\",\n        \"type\" : {\n          \"type\" : \"fixed\",\n          \"name\" : \"FOID\",\n          \"namespace\" : \"sysflow.type\",\n          \"size\" : 20\n        }\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"restype\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"path\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"containerId\",\n        \"type\" : [ \"null\", \"string\" ]\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"ProcessEvent\",\n      \"namespace\" : \"sysflow.event\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"args\",\n        \"type\" : {\n          \"type\" : \"array\",\n          \"items\" : \"string\"\n        }\n      }, {\n        \"name\" : \"ret\",\n        \"type\" : \"int\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"NetworkFlow\",\n      \"namespace\" : \"sysflow.flow\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"endTs\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"sip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"sport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"proto\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"fd\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"numRRecvOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numRRecvBytes\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendBytes\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"gapTime\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"duration\",\n        \"type\" : \"long\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"FileFlow\",\n      \"namespace\" : \"sysflow.flow\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"openFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"endTs\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"fileOID\",\n        \"type\" : \"sysflow.type.FOID\"\n      }, {\n        \"name\" : \"fd\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"numRRecvOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numRRecvBytes\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendBytes\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"gapTime\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"duration\",\n        \"type\" : \"long\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"FileEvent\",\n      \"namespace\" : \"sysflow.event\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"fileOID\",\n        \"type\" : \"sysflow.type.FOID\"\n      }, {\n        \"name\" : \"ret\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"newFileOID\",\n        \"type\" : [ \"null\", \"sysflow.type.FOID\" ]\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"NetworkEvent\",\n      \"namespace\" : \"sysflow.event\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"sip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"sport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"proto\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"ret\",\n        \"type\" : \"int\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"ProcessFlow\",\n      \"namespace\" : \"sysflow.flow\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numThreadsCloned\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"endTs\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numThreadsExited\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numCloneErrors\",\n        \"type\" : \"long\"\n      } ]\n    } ]\n  } ]\n}\n";
#endif

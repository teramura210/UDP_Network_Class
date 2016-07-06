#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define COACH_MESSEAGE 0
#define TEAM_INFO 1

int main(int argc,char *argv[])
{
	int sock;
	struct sockaddr_in addr;
	
	unsigned char buf[250];

	if(argc != 2){
		printf("./kit port_number\n");
		return -1;
	}

	int port = atoi(argv[1]);
	printf("port = %d\n",port);

	sock = socket(AF_INET,SOCK_DGRAM,0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(sock,(struct sockaddr *)&addr,sizeof(addr));
	
	for(int i=0;i<300;i++){
		memset(buf,0,sizeof(buf));
		int n = recv(sock,buf,sizeof(buf),0);
		if(n<0)break;
		if(buf[4] == 7)continue;

		printf("buf = %s \n",buf);
		printf("buf = %d \n",buf);

		printf("=======================================Robocup GameController=========================================\n");	
		printf("header                         (4char)           = %s \n",buf                    );//RGmeが来るはず
		printf("version                        (2char)           = %d \n",buf[4]                 );//
		printf("packet number                  (1char)           = %d \n",buf[6]                 );
		printf("players per team               (1char)           = %d \n",buf[7]                 );
		printf("game type                      (1char)           = %d \n",buf[8]                 );
		printf("state                          (1char)           = %d \n",buf[9]                 );
		printf("first half                     (1char)           = %d \n",buf[10]                );
		printf("kick off team                  (1char)           = %d \n",buf[11]                );
		printf("second ary state               (1char)           = %d \n",buf[12]                );
		printf("drop in team                   (1char)           = %d \n",buf[13]                );
		printf("drop in time                   (2char)           = %d \n",buf[14] + (buf[15]<<8)                );
		printf("secs remaining                 (2char)           = %d \n",buf[16]+(buf[17]<<8)      );
		printf("second ary time                (2char)           = %d \n",buf[18]                );
#if TEAM_INFO
		printf("===================================team info[0]=======================================================\n");
		printf("team number                    (1char)           = %d \n",buf[20]                );
		printf("team color                     (1char)           = %d \n",buf[21]                );
		printf("score                          (1char)           = %d \n",buf[22]                );
		printf("penalty shot                   (1char)           = %d \n",buf[23]                );//ここと
		printf("single shots                   (2char)           = %d \n",buf[24] +(buf[25]<<8));//ここはあまり確かめてない
		printf("coach sequence                 (1char)           = %d \n",buf[26]                );
#if COACH_MESSEAGE
		printf("coach message0                  (char)           = %d \n",buf[27]                );
		printf("             1                                   = %d \n",buf[28]                );
		printf("             2                                   = %d \n",buf[29]                );
		printf("             3                                   = %d \n",buf[30]                );
		printf("             4                                   = %d \n",buf[31]                );
		printf("             5                                   = %d \n",buf[32]                );
		printf("             6                                   = %d \n",buf[33]                );
		printf("             7                                   = %d \n",buf[34]                );
		printf("                                                 = %d \n",buf[35]                );
		printf("                                                 = %d \n",buf[36]                );
		printf("            10                                   = %d \n",buf[37]                );
		printf("                                                 = %d \n",buf[38]                );
		printf("                                                 = %d \n",buf[39]                );
		printf("                                                 = %d \n",buf[40]                );
		printf("                                                 = %d \n",buf[41]                );
		printf("                                                 = %d \n",buf[42]                );
		printf("                                                 = %d \n",buf[43]                );
		printf("                                                 = %d \n",buf[44]                );
		printf("                                                 = %d \n",buf[45]                );
		printf("                                                 = %d \n",buf[46]                );
		printf("            20                                   = %d \n",buf[47]                );
		printf("                                                 = %d \n",buf[48]                );
		printf("                                                 = %d \n",buf[49]                );
		printf("                                                 = %d \n",buf[50]                );
		printf("                                                 = %d \n",buf[51]                );
		printf("                                                 = %d \n",buf[52]                );
		printf("                                                 = %d \n",buf[53]                );
		printf("                                                 = %d \n",buf[54]                );
		printf("                                                 = %d \n",buf[55]                );
		printf("                                                 = %d \n",buf[56]                );
		printf("            30                                   = %d \n",buf[57]                );
		printf("                                                 = %d \n",buf[58]                );
		printf("                                                 = %d \n",buf[59]                );
		printf("                                                 = %d \n",buf[60]                );
		printf("                                                 = %d \n",buf[61]                );
		printf("                                                 = %d \n",buf[62]                );
		printf("                                                 = %d \n",buf[63]                );
		printf("                                                 = %d \n",buf[64]                );
		printf("                                                 = %d \n",buf[65]                );
		printf("                                                 = %d \n",buf[66]                );
		printf("            40                                   = %d \n",buf[67]                );
		printf("                                                 = %d \n",buf[68]                );
		printf("                                                 = %d \n",buf[69]                );
		printf("                                                 = %d \n",buf[70]                );
		printf("                                                 = %d \n",buf[71]                );
		printf("                                                 = %d \n",buf[72]                );
		printf("                                                 = %d \n",buf[73]                );
		printf("                                                 = %d \n",buf[74]                );
		printf("                                                 = %d \n",buf[75]                );
		printf("                                                 = %d \n",buf[76]                );
		printf("            50                                   = %d \n",buf[77]                );
		printf("                                                 = %d \n",buf[78]                );
		printf("                                                 = %d \n",buf[79]                );
		printf("                                                 = %d \n",buf[80]                );
		printf("                                                 = %d \n",buf[81]                );
		printf("                                                 = %d \n",buf[82]                );
		printf("                                                 = %d \n",buf[83]                );
		printf("                                                 = %d \n",buf[84]                );
		printf("                                                 = %d \n",buf[85]                );
		printf("                                                 = %d \n",buf[86]                );
		printf("            60                                   = %d \n",buf[87]                );
		printf("                                                 = %d \n",buf[88]                );
		printf("                                                 = %d \n",buf[89]                );
		printf("                                                 = %d \n",buf[90]                );
		printf("                                                 = %d \n",buf[91]                );
		printf("                                                 = %d \n",buf[92]                );
		printf("                                                 = %d \n",buf[93]                );
		printf("                                                 = %d \n",buf[94]                );
		printf("                                                 = %d \n",buf[95]                );
		printf("                                                 = %d \n",buf[96]                );
		printf("            70                                   = %d \n",buf[97]                );
		printf("                                                 = %d \n",buf[98]                );
		printf("                                                 = %d \n",buf[99]                );
		printf("                                                 = %d \n",buf[100]               );
		printf("                                                 = %d \n",buf[101]               );
		printf("                                                 = %d \n",buf[102]               );
		printf("                                                 = %d \n",buf[103]               );
		printf("                                                 = %d \n",buf[104]               );
		printf("                                                 = %d \n",buf[105]               );
		printf("                                                 = %d \n",buf[106]               );
		printf("            80                                   = %d \n",buf[107]               );
#endif
		printf("robot info coach penalty     (char)              = %d \n",buf[108]               );
		printf("                 secs till unpenalised           = %d \n",buf[109]               );
		printf("           players[0] penalty                    = %d \n",buf[110]               );
		printf("                      secs till unpenalised      = %d \n",buf[111]               );
		printf("           players[1] penalty                    = %d \n",buf[112]               );
		printf("                      secs till unpenalised      = %d \n",buf[113]               );
		printf("           players[2] penalty                    = %d \n",buf[114]               );
		printf("                      secs till unpenalised      = %d \n",buf[115]               );
		printf("           players[3] penalty                    = %d \n",buf[116]               );
		printf("                      secs till unpenalised      = %d \n",buf[117]               );
		printf("           players[4] penalty                    = %d \n",buf[118]               );
		printf("                      secs till unpenalised      = %d \n",buf[119]               );
		printf("           players[5] penalty                    = %d \n",buf[120]               );
		printf("                      secs till unpenalised      = %d \n",buf[121]               );
		printf("           players[6] penalty                    = %d \n",buf[122]               );
		printf("                      secs till unpenalised      = %d \n",buf[123]               );
		printf("           players[7] penalty                    = %d \n",buf[124]               );
		printf("                      secs till unpenalised      = %d \n",buf[125]               );
		printf("           players[8] penalty                    = %d \n",buf[126]               );
		printf("                      secs till unpenalised      = %d \n",buf[127]               );
		printf("           players[9] penalty                    = %d \n",buf[128]               );
		printf("                      secs till unpenalised      = %d \n",buf[129]               );
		printf("           players[10] penalty                   = %d \n",buf[130]               );
		printf("                       secs till unpenalised     = %d \n",buf[131]               );
		printf("==============================================team info[1]============================================\n");
		printf("team number                    (1char)           = %d \n",buf[132]               );
		printf("team color                     (1char)           = %d \n",buf[133]               );
		printf("score                          (1char)           = %d \n",buf[134]               );
		printf("penalty shot                   (1char)           = %d \n",buf[135]               );
		printf("single shots                   (2char)           = %d \n",(buf[136] <<8) + buf[137]);
		printf("coach sequence                 (1char)           = %d \n",buf[138]                );
#if COACH_MEASSEGE
		printf("coach message0                  (char)           = %d \n",buf[139]                );
		printf("             1                                   = %d \n",buf[140]                );
		printf("             2                                   = %d \n",buf[141]                );
		printf("             3                                   = %d \n",buf[142]                );
		printf("             4                                   = %d \n",buf[143]                );
		printf("             5                                   = %d \n",buf[144]                );
		printf("             6                                   = %d \n",buf[145]                );
		printf("             7                                   = %d \n",buf[146]                );
		printf("                                                 = %d \n",buf[147]                );
		printf("                                                 = %d \n",buf[148]                );
		printf("            10                                   = %d \n",buf[149]                );
		printf("                                                 = %d \n",buf[150]                );
		printf("                                                 = %d \n",buf[151]                );
		printf("                                                 = %d \n",buf[152]                );
		printf("                                                 = %d \n",buf[153]                );
		printf("                                                 = %d \n",buf[154]                );
		printf("                                                 = %d \n",buf[155]                );
		printf("                                                 = %d \n",buf[156]                );
		printf("                                                 = %d \n",buf[157]                );
		printf("                                                 = %d \n",buf[158]                );
		printf("            20                                   = %d \n",buf[159]                );
		printf("                                                 = %d \n",buf[160]                );
		printf("                                                 = %d \n",buf[161]                );
		printf("                                                 = %d \n",buf[162]                );
		printf("                                                 = %d \n",buf[163]                );
		printf("                                                 = %d \n",buf[164]                );
		printf("                                                 = %d \n",buf[165]                );
		printf("                                                 = %d \n",buf[166]                );
		printf("                                                 = %d \n",buf[167]                );
		printf("                                                 = %d \n",buf[168]                );
		printf("            30                                   = %d \n",buf[169]                );
		printf("                                                 = %d \n",buf[170]                );
		printf("                                                 = %d \n",buf[171]                );
		printf("                                                 = %d \n",buf[172]                );
		printf("                                                 = %d \n",buf[173]                );
		printf("                                                 = %d \n",buf[174]                );
		printf("                                                 = %d \n",buf[175]                );
		printf("                                                 = %d \n",buf[176]                );
		printf("                                                 = %d \n",buf[177]                );
		printf("                                                 = %d \n",buf[178]                );
		printf("            40                                   = %d \n",buf[179]                );
		printf("                                                 = %d \n",buf[180]                );
		printf("                                                 = %d \n",buf[181]                );
		printf("                                                 = %d \n",buf[182]                );
		printf("                                                 = %d \n",buf[183]                );
		printf("                                                 = %d \n",buf[184]                );
		printf("                                                 = %d \n",buf[185]                );
		printf("                                                 = %d \n",buf[186]                );
		printf("                                                 = %d \n",buf[187]                );
		printf("                                                 = %d \n",buf[188]                );
		printf("            50                                   = %d \n",buf[189]                );
		printf("                                                 = %d \n",buf[190]                );
		printf("                                                 = %d \n",buf[191]                );
		printf("                                                 = %d \n",buf[192]                );
		printf("                                                 = %d \n",buf[193]                );
		printf("                                                 = %d \n",buf[194]                );
		printf("                                                 = %d \n",buf[195]                );
		printf("                                                 = %d \n",buf[196]                );
		printf("                                                 = %d \n",buf[197]                );
		printf("                                                 = %d \n",buf[198]                );
		printf("            60                                   = %d \n",buf[199]                );
		printf("                                                 = %d \n",buf[200]                );
		printf("                                                 = %d \n",buf[201]                );
		printf("                                                 = %d \n",buf[202]                );
		printf("                                                 = %d \n",buf[203]                );
		printf("                                                 = %d \n",buf[204]                );
		printf("                                                 = %d \n",buf[205]                );
		printf("                                                 = %d \n",buf[206]                );
		printf("                                                 = %d \n",buf[207]                );
		printf("                                                 = %d \n",buf[208]                );
		printf("            70                                   = %d \n",buf[209]                );
		printf("                                                 = %d \n",buf[210]                );
		printf("                                                 = %d \n",buf[211]                );
		printf("                                                 = %d \n",buf[212]               );
		printf("                                                 = %d \n",buf[213]               );
		printf("                                                 = %d \n",buf[214]               );
		printf("                                                 = %d \n",buf[215]               );
		printf("                                                 = %d \n",buf[216]               );
		printf("                                                 = %d \n",buf[217]               );
		printf("                                                 = %d \n",buf[218]               );
		printf("            80                                   = %d \n",buf[219]               );
#endif
		printf("robot info coach penalty     (char)              = %d \n",buf[220]);
		printf("                 secs till unpenalised           = %d \n",buf[221]);
		printf("           players[0] penalty                    = %d \n",buf[222]);
		printf("                      secs till unpenalised      = %d \n",buf[223]);
		printf("           players[1] penalty                    = %d \n",buf[224]);
		printf("                      secs till unpenalised      = %d \n",buf[225]);
		printf("           players[2] penalty                    = %d \n",buf[226]);
		printf("                      secs till unpenalised      = %d \n",buf[227]);
		printf("           players[3] penalty                    = %d \n",buf[228]);
		printf("                      secs till unpenalised      = %d \n",buf[229]);
		printf("           players[4] penalty                    = %d \n",buf[230]);
		printf("                      secs till unpenalised      = %d \n",buf[231]);
		printf("           players[5] penalty                    = %d \n",buf[232]);
		printf("                      secs till unpenalised      = %d \n",buf[233]);
		printf("           players[6] penalty                    = %d \n",buf[234]);
		printf("                      secs till unpenalised      = %d \n",buf[235]);
		printf("           players[7] penalty                    = %d \n",buf[236]);
		printf("                      secs till unpenalised      = %d \n",buf[237]);
		printf("           players[8] penalty                    = %d \n",buf[238]);
		printf("                      secs till unpenalised      = %d \n",buf[239]);
		printf("           players[9] penalty                    = %d \n",buf[240]);
		printf("                      secs till unpenalised      = %d \n",buf[241]);
		printf("           players[10] penalty                   = %d \n",buf[242]);
		printf("                       secs till unpenalised     = %d \n",buf[243]);
		printf("======================================================================================================\n");
#endif
	}
	close(sock);
	return 0;
}

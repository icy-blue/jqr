/* <--- ���˻����˳��� --->
----���ڣ�2018-05-22---*/

/*---- Ԥ����켣�����˴������˿� ----*/
#define gdf1 geteadc(1)
#define gdf2 geteadc(2)
#define gdf3 geteadc(3)
#define gdf4 geteadc(4)
#define gdb1 geteadc(5)
#define gdb2 geteadc(6)
#define gdb3 geteadc(7)
#define gdb4 geteadc(8)
#define gdl getadc(1)
#define gdr getadc(2)
#define dh_b getadc(3)
#define dh_l getadc(4)
#define cj getadc(5)

#define ks getport(7)
#define kz getport(8)
#define kx getport(9)

/*<-- �������� -->*/
//�����ӳ���

void test_sjzz(void);     //����װ�ò���
void test_adc(void);     //����������
void test_dc(void);      //�������
void test_jxs(void);     //��е�ֲ���
void run(int x,int y);   //�������
//�����ӳ���
void guixia(void);       //��е�۹�λ
void guizhong(void);     //��е�����м�
void guishang(void);       //��е�����Ϸ�

void go_line_f(void);    //ǰ����Ѱ����   
void go_line_f_m(void);  //ǰ����Ѱ���� 
void go_line_f_ms(void);  //ǰ����manѰ����
void go_dwz_ce(void);       //��ceλ������       
void go_f(int x);        //ǰѰ��������   
void go_line_b(void);    //�����Ѱ����
void go_line_bm(void);    //������Ѱ����               
void go_b(int x);        //��Ѱ��������   
void turn_r(int x);      //������ת��   
void turn_l(int x);      //������ת��   
void zhua(void);         //ץ���
void fang(void);         //�����
void go_dwz_z(void);     //ץ���ǰ��λ��
void go_dwz_zj(void);     //ץ���ǰ��λ��zhongjiandingwei
void go_dwz_f(void);     //�����ǰ��λ��
void go_dwz_fr(void);    //�����ǰ��λ�ã��ҵػҶ�
void go_dwz_fl(void);    //�����ǰ��λ�ã���ػҶ�
void yssb(void);         //�����ɫ����
void f_a(void);          //fa���
void f_b(void);
void f_c(void);
void f_d(void);
void f_e(void);
void g_a(void);          //ga���
void g_b(void);
void g_c(void);
void g_d(void);
void g_e(void);
 
void renwu_1(void);      //����һ 
//����һ�����ӳ���
void c_dao_hei(void);
void c_dao_lan(void);
void c_dao_lv(void);
void c_dao_bai(void);
void c_dao_hong(void); 

void e_dao_hei(void);
void e_dao_lan(void);
void e_dao_lv(void);
void e_dao_bai(void);
void e_dao_hong(void);

void a_dao_hei(void);
void a_dao_lan(void);
void a_dao_lv(void);
void a_dao_bai(void); 
void a_dao_hong(void);

void e_dao_hei1(void);
void e_dao_lan1(void);
void e_dao_lv1(void);
//void e_dao_bai1(void);
void e_dao_hong1(void);

void a_dao_hei1(void);
void a_dao_lan1(void);
void a_dao_lv1(void);
//void a_dao_bai1(void); 
void a_dao_hong1(void);

void renwu_2(void);      //��hei_f
void hei_f(void);
void lan_f(void);
void lv_f(void);
void bai_f(void);
void hong_f(void);
void hei_fd(void); 
void lan_fd(void);
void lv_fd(void);
void bai_fd(void);
void hong_fd(void);
void hei_g(void); 
void lan_g(void);
void lv_g(void);
void bai_g(void);
void hong_g(void);
void hei_gd(void); 
void lan_gd(void);
void lv_gd(void);
void bai_gd(void);
void hong_gd(void);


/*<-- �������� -->*/
int pcs,wkys,bz;            
int dhf1=478,dhf2=617,dhf3=435,dhf4=434;//ǰ4���ػҺڰ��м�ֵ
int dhb1=676,dhb2=635,dhb3=522,dhb4=452;//��4���ػҺڰ��м�ֵ
int dhl=521,dhr=622;                    //�м�����2���ػҺڰ��м�ֵ
int i_hei=0,i_lan=0,i_lv=0,i_bai=0,i_hong=0; //�����ɫ���ץȡ����
int wk_hei_b=633,wk_lan_b=537,wk_lv_b=414,wk_bai_b=272,wk_hong_b=427;//��ɫ�ҶȲ���ĸ��������ɫֵ
int wk_hei_l=668,wk_lan_l=533,wk_lv_l=275,wk_bai_l=210,wk_hong_l=570;//��ɫ�ҶȲ���ĸ��������ɫֵ
int zwk=74,fwk=54,xwk=43;                        //ץ���Ƕȣ������Ƕ�
int i_b=0,i_w=0,i_wkf=0,i_wkg=0,i_wk=0;  //���
int cbai=0,hx=0,bz=1,b=0,ii=0;           //��� 
int cj_cs=0,cj_max=0;  

//int ks,kz,kx;             //����װ���������� ������       
float t,tt=0,t1=0;
float i_t=0.001;   //����ʱ�����������߼�ʱ��0.0005ÿ�Σ������߼�


/*<-- ������ -->*/
int main(void)
{
  pcs=selector();
  if(pcs==0) test_adc();        //����������
  else if(pcs==1) test_dc();    //�������
  else if(pcs==2) test_jxs();   //��е�ֲ���
  else if(pcs==3) test_sjzz();   //����װ�ò��� 
  else if(pcs==4){wait(1);renwu_1();while(1){;}}
  else if(pcs==5){wait(1);renwu_2();while(1){;}}
  else if(pcs==6) bai_fd();
  else if(pcs==7) g_e();
  else if(pcs==8) f_d();
  else 
  
  renwu_1();
  renwu_2();
  
}

//�����
void renwu_2(void)
{
 f_a();
 f_b();
 f_c();
 f_e();
 f_d();
 g_b();
 g_a();
 g_e();
 g_c();
 g_d();
}

/////////////////F//////////////////////////
void hei_f(void)
{
 go_b(5);   //��������
 turn_l(2); //��ת����
 go_dwz_f();//��λ��
 fang();    //�����   
 go_b(5);   //��������
 turn_r(2); //��ת����
}
void hei_fd(void)
{
 go_b(5);   //��������
 turn_l(2); //��ת����
 go_dwz_f();//��λ��
 fang();    //�����  
 go_b(3);   
 turn_r(2);
 go_f(2);
// turn_l(1);
}
void lan_f(void)
{ 
 go_b(3);   //��������
 turn_l(3); //��ת����
 go_f(2);   //ǰ����һ
// turn_r(1);
 go_dwz_f();//��λ��
 fang();    //�����    
 go_b(3);  //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
// turn_l(1);
}
void lan_fd(void)
{
 go_b(3);   //��������
 turn_l(3); //��ת����
 go_f(2);   //ǰ����һ
// turn_r(1);
 go_dwz_f();//��λ��
 fang();    //�����    
 go_b(1);   
 turn_r(1);
 go_f(1);
 turn_l(1);
}
void lv_f(void)
{
 go_b(1);   //������һ
 turn_r(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_l(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����  
 go_b(1);   //������һ
 turn_l(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
}
void lv_fd(void)
{
 go_b(1);   //������һ
 turn_r(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_l(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����  
 go_b(3);   //������һ
 turn_l(3); //��ת��һ
 go_f(2);   //ǰ����һ
}
void bai_f(void)
{
 go_b(3);   //������һ
 turn_r(2); //��ת��һ
 run(200,200);wait(0.5);
 go_f(1);   //ǰ������
 go_dwz_f();//��λ��
 fang();    //����� 
 go_b(3);  //������һ
 turn_l(2); //��ת��һ
 run(200,200);wait(0.5);
 go_f(1);  //ǰ������

}
void bai_fd(void)
{
 go_b(3);wait(0.1);   //������һ
 
 wait(5);
 
 turn_r(2); //��ת��һ
 
 wait(5);
 
 run(100,100);
 wait(0.3);
 run(0,0);
 
 //go_f(2);   //ǰ������
 go_f(1);
 
 wait(5);
 
 go_dwz_f();//��λ��

 wait(5);
 
 fang();    //����� 
 go_b(5);   //������һ
 turn_l(2); //��ת��һ
}
void hong_f(void)
{
 go_b(3); //wait(0.1);{if(gdb2>dhb2&&gdb3>dhb3) go_b(1);}   //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����     
 go_b(3);wait(0.1);   //��������
 turn_l(3); //��ת����
 go_f(2);   //ǰ����һ

}
void hong_fd(void)
{
 go_b(3);   //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����     
 go_b(3);   //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
}
/////////////////G//////////////////////////
void hei_g(void)
{
 go_b(3); //wait(2);  //������һ
 turn_l(2); //��ת��һ
 run(200,200);wait(0.5);
 go_f(1);   //ǰ������
 go_dwz_f();//��λ��
 fang();    //�����     
 go_b(3);   //������һ
 turn_r(2); //��ת��һ
 go_f(2);   //ǰ������
}
void hei_gd(void)
{
 go_b(3);   //������һ
 turn_l(2); //��ת��һ
 run(200,200);wait(0.5);
 go_f(1);   //ǰ������
 go_dwz_f();//��λ��
 fang();    //����� 
 go_b(3);   //��������
 turn_r(3); //��ת����
 go_f(3);   //ǰ������
}
void lan_g(void)
{
 go_b(1);   //������һ
 turn_l(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����  
 go_b(1);   //������һ
 turn_r(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_l(1); //��ת��һ
}
void lan_gd(void)
{
 go_b(1);   //������һ
 turn_l(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����  
 go_b(3);   //��������
 turn_r(2); //��ת����
 go_f(3);   //ǰ����һ
}
void lv_g(void)
{
 go_b(3);   //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����    
 go_b(3);   //��������
 turn_l(3); //��ת����
 go_f(2);   //ǰ����һ
}
void lv_gd(void)
{
 go_b(3);   //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����   
 go_b(3);   //������һ
 turn_l(2); //��ת��һ
 go_f(3);   //ǰ����һ

}
void bai_g(void)
{
 go_b(5);   //��������
 turn_l(2); //��ת����
 go_dwz_f();//��λ��
 fang();    //�����   
 go_b(5);   //��������
 turn_l(2); //��ת����
}
void bai_gd(void)
{
 go_b(5);   //��������
 turn_l(2); //��ת����
 go_dwz_f();//��λ��
 fang();    //�����   
  go_b(3);   //������һ
  turn_l(3); //��ת��һ
  go_f(3);   //ǰ������
}
void hong_g(void)
{
 go_b(3);   //��������
 turn_l(3); //��ת����
 go_f(2);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����     
 go_b(3);   //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
}
void hong_gd(void)
{
 go_b(3);   //��������
 turn_l(3); //��ת����
 go_f(2);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����   
 go_b(7);   //��������
}

//����һA����
void renwu_1(void)
{ 
 wait(0.3);servo(4,fwk);servo(3,120);
 go_f(5);    //ǰ������
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//һ����
 if(wkys==1)c_dao_hei();
 else if(wkys==2)c_dao_lan();
 else if(wkys==3)c_dao_lv();
 else if(wkys==4)c_dao_bai();
 else c_dao_hong();
} 

//ץ�㵽�ŵ�
//һ��
void c_dao_hei(void)
{
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_l(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����
//��ɫ���������E,ץ���
 go_b(3);   //��������
 turn_r(1); //��ת��һ
 go_dwz_z();//��λ��
 zhua();//ץ���������ɫ
//��ת������
 if(wkys==2)e_dao_lan();
 else if(wkys==3)e_dao_lv();
 else if(wkys==4)e_dao_bai();
 else e_dao_hong();
}

void c_dao_lan(void)
{
 go_f(1);    //ǰ����һ
 turn_r(1);  //��ת��һ
 go_f(1);    //ǰ����һ
 turn_l(1);  //��ת��һ
 go_f(1);    //ǰ����һ
 turn_r(1);  //��ת��һ
 go_dwz_fr();//ǰ�Ҷ�λ��
 fang();     //�����
//��ɫ���������E,ץ���
 go_b(1);    //������һ
 turn_r(1);  //��ת��һ
 go_f(3);    //ǰ������
 turn_l(3);  //��ת����
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==1)e_dao_hei();
 else if(wkys==3)e_dao_lv();
 else if(wkys==4)e_dao_bai();
 else e_dao_hong();
}

void c_dao_lv(void)
{
 go_f(1);    //ǰ����һ
 turn_l(1);  //��ת��һ
 go_f(1);    //ǰ����һ
 turn_r(1);  //��ת��һ
 go_f(1);    //ǰ����һ
 turn_l(1);  //��ת��һ
 go_dwz_fl();//ǰ���λ��
 fang();     //�����
//��ɫ���������E,ץ���
 t=seconds(1);tt=t+0.2;
 while(gdl<dhl||t<tt){t=seconds(1);go_line_b();}//������һ
 turn_l(1);  //��ת��һ
 go_f(3);    //ǰ������
 turn_l(1);  //��ת��һ
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==1)e_dao_hei();
 else if(wkys==2)e_dao_lan();
 else if(wkys==4)e_dao_bai();
 else e_dao_hong();
}

void c_dao_bai(void)
{
 cbai=1;
 go_f(1);    //ǰ����һ
 turn_l(1);  //��ת��һ
 go_f(1);    //ǰ����һ
 turn_r(1);  //��ת��һ
 go_dwz_f(); //��λ��
 fang();     //�����
//��ɫ���������E,ץ���
 go_b(3);    //��������
 turn_l(1);  //��ת��һ
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==1)a_dao_hei1();
 else if(wkys==2)a_dao_lan1();
 else if(wkys==3)a_dao_lv1();
 else a_dao_hong1();
}
void c_dao_hong(void)
{
 go_f(1);    //ǰ����һ
 go_dwz_f(); //��λ��
 fang();     //�����
//��ɫ���������E,ץ���
 go_b(3);    //��������
 turn_r(2);  //��ת����
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==1)e_dao_hei();
 else if(wkys==2)e_dao_lan();
 else if(wkys==3)e_dao_lv();
 else e_dao_bai();
}


//����
void e_dao_hei(void)
{
 go_f(1);   //ǰ����һ
 turn_l(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����
//��ɫ���������A,ץ���
 go_b(3);   //��������
 turn_l(3); //��ת����
 go_dwz_z();//��λ��
 zhua();    //ץ���������ɫ
//��ת������
 if(wkys==2)a_dao_lan();
 else if(wkys==3)a_dao_lv();
 else if(wkys==4)a_dao_bai();
 else a_dao_hong();
}

void e_dao_lan(void)
{
 go_f(1);    //ǰ����һ
 go_dwz_f(); //��λ��
 fang();     //�����
//��ɫ���������A,ץ���
 go_b(3);    //������һ
 turn_l(4);  //��ת����
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==1)a_dao_hei();
 else if(wkys==3)a_dao_lv();
 else if(wkys==4)a_dao_bai();
 else a_dao_hong();
}

void e_dao_lv(void)
{
  go_b(2);    //ǰ����һ
  turn_l(3);  //��ת��һ
  go_f(3);    //ǰ������
//  turn_r(1);  //��ת��һ
//  go_f(1);    //ǰ����һ
  turn_l(1);  //��ת��һ
  go_dwz_fl();//ǰ���λ��
  fang();     //�����
//��ɫ���������E,ץ���
  t=seconds(1);tt=t+0.2;
  while(gdl<dhl||t<tt){t=seconds(1);go_line_b();}//������һ
  turn_l(1);  //��ת��һ
  go_f(3);    //ǰ������
  turn_r(3);  //��ת����
  go_dwz_z(); //��λ��
  zhua();     //ץ���������ɫ
//��ת������
  if(wkys==1)a_dao_hei();
  else if(wkys==2)a_dao_lan();
  else if(wkys==4)a_dao_bai();
  else a_dao_hong();
}
void e_dao_bai(void)
{
 go_b(2);     //ǰ����һ
 turn_l(3);   //��ת��һ
 go_f(2);     //ǰ������
// turn_r(1);   //��ת��һ
 go_dwz_f();  //��λ��
 fang();      //�����
//��ɫ���������A,ץ���
 go_b(3);     //��������
 turn_l(1);   //��ת��һ
 go_dwz_z();  //��λ��
 zhua();      //ץ���������ɫ
//��ת������
 if(wkys==1)a_dao_hei();
 else if(wkys==2)a_dao_lan();
 else if(wkys==3)a_dao_lv();
 else if(wkys==4)a_dao_bai(); 
 else a_dao_hong();
}

void e_dao_hong(void)
{
 go_b(2);    //ǰ����һ
 turn_l(2);  //��ת��һ
 go_f(1);   //ǰ������
// turn_r(1);  //��ת��һ
 go_dwz_f(); //��λ��
 fang();     //�����
//��ɫ���������E,ץ���
 go_b(3);    //��������
 turn_l(2);  //��ת����
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==1)a_dao_hei();
 else if(wkys==2)a_dao_lan();
 else if(wkys==3)a_dao_lv();
 else a_dao_bai();
}


//����

void a_dao_hei(void)
{
 go_b(2);   //ǰ����һ
 turn_r(3); //��ת��һ
 go_f(2);   //ǰ������
// turn_l(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����
 go_b(5);   //��������
 turn_l(2); //��ת��һ
 
 sound(500,500);//while(1){;}
}
void a_dao_lan(void)
{
 go_b(4);   //��������
 turn_r(2); //��ת����
 go_dwz_f();//��λ��
 fang();    //�����
 go_b(3);  //��������
 turn_r(3); //��ת����
 go_f(2);   //ǰ����һ
 
 sound(500,500);//while(1){;}
}
void a_dao_lv(void)
{
 go_f(1);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����
 go_b(1);   //������һ
 turn_l(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 
 sound(500,500);//while(1){;}
}

void a_dao_bai(void)
{
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_l(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����
 go_b(3);   //������һ
 turn_l(2); //��ת��һ
 go_f(1);  //ǰ������
 sound(500,500);//while(1){;}
}
void a_dao_hong(void)
{
 go_b(2);   //ǰ����һ
 turn_r(2); //��ת��һ
 go_f(2);   //ǰ������

 go_dwz_f();//��λ��
 fang();    //�����
 go_b(3);   //��������
 turn_l(3); //��ת����
 go_f(2);   //ǰ����һ 
 sound(500,500);//while(1){;}
}
//����һB����


void a_dao_hei1(void)
{
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_f(3);   //ǰ������
 turn_l(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����
 go_b(3);   //��������
 turn_r(1); //��ת��һ
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==2)e_dao_lan1();
 else if(wkys==3)e_dao_lv1();
// else if(wkys==4)e_dao_bai();
 else e_dao_hong1();
 sound(500,500);//while(1){;}
}
void a_dao_lan1(void)
{
 go_f(1);
 turn_r(1);
 go_f(3);
 turn_l(1);
 go_f(1);
 turn_r(1);
 go_dwz_fr();//��λ��
 fang();    //�����
 go_b(1);   //��������
 turn_r(1); //��ת����
 go_f(3);   //ǰ����һ
 turn_l(3);
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==2)e_dao_lan1();
 else if(wkys==3)e_dao_lv1();
// else if(wkys==4)e_dao_bai();
 else e_dao_hong1();
 sound(500,500);//while(1){;}
}
void a_dao_lv1(void)
{
 go_f(1);   //ǰ����һ
 go_dwz_f();//��λ��
 fang();    //�����
 go_b(3);   //������һ
 turn_r(4); //��ת��һ
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==2)e_dao_lan1();
 else if(wkys==3)e_dao_lv1();
// else if(wkys==4)e_dao_bai();
 else e_dao_hong1();
 
 sound(500,500);//while(1){;}
}

void a_dao_hong1(void)
{
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_f(2);   //ǰ������
 turn_l(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����
 go_b(3);   //��������
 turn_r(2); //��ת����
 go_dwz_z(); //��λ��
 zhua();     //ץ���������ɫ
//��ת������
 if(wkys==1)e_dao_hei1();
 else if(wkys==2)e_dao_lan1();
 else if(wkys==3)e_dao_lv1();
// else if(wkys==4)e_dao_bai();
 else e_dao_hong1();
 
 sound(500,500);//while(1){;}
}

//����B����

void e_dao_hei1(void)
{
 go_f(1);   //ǰ����һ
 turn_l(1); //��ת��һ
 go_f(1);   //ǰ����һ
 turn_r(1); //��ת��һ
 go_dwz_f();//��λ��
 fang();    //�����
//��ɫ���������A,ץ���
 go_b(5);   //��������
 turn_r(2); //��ת����
 
}

void e_dao_lan1(void)
{
 go_f(1);    //ǰ����һ
 go_dwz_f(); //��λ��
 fang();     //�����
//��ɫ���������A,ץ���
 go_b(1);    //������һ
 turn_r(1);  //��ת����
 go_f(3);
 turn_l(1);
}

void e_dao_lv1(void)
{
  go_b(4); 
  turn_r(2);  //��ת��һ
  go_dwz_f();
  fang();     //�����
  go_b(1);  
  turn_l(1);  //��ת��һ
  go_f(1);    //ǰ������
  turn_r(1);  //��ת����
  
}

void e_dao_hong1(void)
{
 go_f(1);    //ǰ����һ
 turn_l(1);  //��ת��һ
 go_f(2);    //ǰ������
 turn_r(1);  //��ת��һ
 go_dwz_f(); //��λ��
 fang();     //�����
//��ɫ���������E,ץ���
 go_b(1);    //��������
 turn_l(1);  //��ת����
 go_f(3);
 turn_r(1); 
}



/*-- ѭ�� --*/
//����
void go_line_f(void)
{
 if(gdf2>dhf2&&gdf3>dhf3||gdf1>dhf1&&gdf4>dhf4){run(600,600);}
 else if(gdf2>dhf2&&gdf3<dhf3) run(350,750);      
 else if(gdf3>dhf3&&gdf2<dhf2) run(750,350); 
 else if(gdf1>dhf1) run(300,800);      
 else if(gdf4>dhf4) run(800,300);    
 else {run(550,550); }                 
}

/*
void go_line_f0(void)
{
 if(gdf2>dhf2&&gdf3>dhf3||gdf1>dhf1&&gdf4>dhf4){run(600,600);}
 else if(gdf2>dhf2) run(350,750);      
 else if(gdf3>dhf3) run(750,350); 
 else if(gdf1>dhf1) run(200,900);      
 else if(gdf4>dhf4) run(900,200);    
 else {run(550,550); }                 
}
*/
//����
void go_line_f_m(void)
{
 if(gdf2>dhf2&&gdf3>dhf3||gdf1>dhf1&&gdf4>dhf4){run(250,250);}
 else if(gdf2>dhf2) run(300,550);      
 else if(gdf3>dhf3) run(500,300); 
 else if(gdf1>dhf1) run(170,600);      
 else if(gdf4>dhf4) run(600,200);    
 else {run(250,250); }               
}
//������
void go_line_f_ms(void)
{
 if(gdf2>dhf2&&gdf3>dhf3||gdf1>dhf1&&gdf4>dhf4){run(150,160);}
 else if(gdf2>dhf2) run(150,250);      
 else if(gdf3>dhf3) run(250,150); 
 else if(gdf1>dhf1) run(100,400);      
 else if(gdf4>dhf4) run(400,100);    
 else {run(150,160); }               
}
//ǰ������
void go_f(int x)
{
 hx=0;b=1;i_b=0;i_w=0;
 while(hx<x)
 {
   t=seconds(1);
   go_line_f();
  
   if(gdl>dhl+20){
	   if(i_b<1000)i_b++;
   }
   else i_b=0;
   if(gdl<dhl-20){
	   if(i_w<1000)i_w++;
   }
   else i_w=0;
  
   if(i_b>1 && t>tt && b==0){
	   hx=hx+1;
	   if(hx==x) break;
	   b=1; tt=t+0.001;
   } 
   if(i_w>3 && t>tt && b==1){
	   b=0; tt=t+0.001;
   }
  }
  run(0,0);tt=t+0.005;
}
//��Ѱ��
void go_line_b(void)
{
 if(gdb2>dhb2&&gdb3>dhb3||gdb1>dhb1&&gdb4>dhb4)
 {
  run(-450,-450);
  }
 else if(gdb2>dhb2) run(-600,-350);      
 else if(gdb3>dhb3) run(-350,-650); 
 else if(gdb1>dhb1) run(-750,-300);     
 else if(gdb4>dhb4) run(-300,-800);
 else run(-450,-450);                  
}
//��Ѱ������
void go_line_bm(void)
{
 if(gdb2>dhb2&&gdb3>dhb3||gdb1>dhb1&&gdb4>dhb4)
 {
  run(-150,-150);
  }
 else if(gdb2>dhb2) run(-300,-130);      
 else if(gdb3>dhb3) run(-130,-300); 
 else if(gdb1>dhb1) run(-500,-100);     
 else if(gdb4>dhb4) run(-100,-500);
 else run(-150,-150);                  
}
//��������
void go_b(int x)
{
 hx=0;b=1;i_b=0;i_w=0;
 while(hx<x)
 {
   t=seconds(1);
   go_line_b();
  
   if(gdr>dhr+10){if(i_b<1000)i_b++;}else i_b=0;
   if(gdr<dhr-10){if(i_w<1000)i_w++;}else i_w=0;
  
   if(i_b>1&&t>tt&&b==0){hx=hx+1;if(hx==x) break;b=1;tt=t+0.001;} 
   if(i_w>3&&t>tt&&b==1){b=0;tt=t+0.001;}
  }
  run(0,0);tt=t+0.005;
}
//������ת
void turn_r(int x)
{
// run(300,300);wait(0.1);
 if(gdf4>dhf4){x=x-1;}//sound(500,500);
 run(450,-450);wait(0.06);
 hx=0;b=1;i_b=0;i_w=0;
 while(hx<x)
 {
   t=seconds(1);
   
   if(gdf4>dhf4+20){if(i_b<1000)i_b++;}else i_b=0;
   if(gdf4<dhf4-20){if(i_w<1000)i_w++;}else i_w=0;
  
   if(i_b>1&&t>tt&&b==0){hx=hx+1;if(hx==x) break;b=1;tt=t+i_t;} 
   if(i_w>3&&t>tt&&b==1){b=0;tt=t+i_t;}
  }
 while(gdf4>dhf4){;}wait(0.08);//run(0,0);wait(5);
 t=seconds(1);tt=t+0.25;
 while(t<tt){t=seconds(1);go_line_f();}
 run(0,0);
 //wait(1);
}
//������ת
void turn_l(int x)
{
// run(300,300);wait(0.1);
 if(gdf1>dhf1){x=x-1;}//sound(500,500);
 run(-450,460);wait(0.06);
 hx=0;b=1;i_b=0;i_w=0;
 while(hx<x)
 {
   t=seconds(1);
   
   if(gdf1>dhf1+20){if(i_b<1000)i_b++;}else i_b=0;
   if(gdf1<dhf1-20){if(i_w<1000)i_w++;}else i_w=0;
  
   if(i_b>1&&t>tt&&b==0){hx=hx+1;if(hx==x) break;b=1;tt=t+i_t;} 
   if(i_w>3&&t>tt&&b==1){b=0;tt=t+i_t;}
  }
 while(gdf1>dhf1){;}wait(0.08);//run(0,0);wait(5);
 t=seconds(1);tt=t+0.25;
 while(t<tt){t=seconds(1);go_line_f();}
 run(0,0);
 //wait(1);
}
//��ץ���λ������
void go_dwz_z(void)
{
 
 while(gdf1<dhf1||gdf4<dhf4)
 {
  if(gdf1>dhf1){run(200,300);while(gdf4<dhf4) {;}}
  else if(gdf4>dhf4){run(300,200);while(gdf1<dhf1) {;}} 
  else if(cj>400)go_line_f_m();
  else go_line_f();
  }
 run(0,0);
}
//��ץ���λ������zhongjiandingwei
void go_dwz_zj(void)
{
 
 while(gdl<dhl)
 {
  if(gdl>dhl)run(0,0); 
  else if(cj>480)go_line_f_ms();
  else go_line_f_m();
   }
   run(0,0);
}
//��c��eλ������
void go_dwz_ce(void)
{
// run(100,250);wait(0.3);
 while(cj<550)
 {
  if(gdr<dhr&&gdl>dhl) {run(100,200);}
//  else if(gdr>dhr&&gdl>dhl) 
  else if(gdr<dhr&&gdl<dhl) {run(0,0);break;}
  else go_line_f_ms();
   }
   run(0,0);
}
//�Է����λ������
void go_dwz_f(void)
{
 //servo(4,fwk);
 while(gdf1<dhf1||gdf4<dhf4)
 {
  if(gdf1>dhf1){run(150,350);while(gdf4<dhf4) {;}}
  else if(gdf4>dhf4){run(350,150);while(gdf1<dhf1) {;}} 
  else go_line_f_m();
  }
 //run(0,0);wait(0.1);
 run(-100,-100);wait(0.08);
 run(0,0);
}

//ǰ�Ҷ����
void go_dwz_fr(void)
{
 //servo(4,fwk);
 while(gdf4<dhf4)
 {
  if(gdf2>dhf2&&gdf3>dhf3){run(500,300);}
  else if(gdf2>dhf2) run(300,400);      
  else if(gdf3>dhf3) run(550,300); 
  else if(gdf1>dhf1) run(200,500);      
  else {run(500,300); }
  }
 //run(0,0);wait(0.1);
 run(0,0);
}
//ǰ������
void go_dwz_fl(void)
{
 //servo(4,fwk);
 while(gdf1<dhf1)
 {
  if(gdf2>dhf2&&gdf3>dhf3){run(300,500);}
  else if(gdf3>dhf3) run(400,300); 
  else if(gdf2>dhf2) run(200,450);      
  else if(gdf4>dhf4) run(500,200);      
  else {run(300,500); }
  }
 //run(0,0);wait(0.1);
 run(0,0);
}

void yssb(void)
{
 //wk_hei=500,wk_lan=400,wk_lv=300,wk_bai=200,wk_hong=100;
 //��ys=1,��ys=2,��ɫys=3,��ɫys=4,��ys=5.
 //i_hei=0,i_lan=0,i_lv=0,i_bai=0,i_wk=0;

 if(dh_b>wk_hei_b -50&&dh_b<wk_hei_b +50&&dh_l>wk_hei_l -50&&dh_l<wk_hei_l +50)wkys=1;
 else if(dh_b>wk_lan_b -50&&dh_b<wk_lan_b +50&&dh_l>wk_lan_l -50&&dh_l<wk_lan_l +50)wkys=2;
 else if(dh_b>wk_lv_b  -50&&dh_b<wk_lv_b  +50&&dh_l>wk_lv_l  -50&&dh_l<wk_lv_l  +50)wkys=3;
 else if(dh_b>wk_bai_b -50&&dh_b<wk_bai_b +50&&dh_l>wk_bai_l -50&&dh_l<wk_bai_l +50)wkys=4;
 else if(dh_b>wk_hong_b-50&&dh_b<wk_hong_b+50&&dh_l>wk_hong_l-50&&dh_l<wk_hong_l+50)wkys=5;
 else wkys=0;
}

/*---����װ��λ��ȷ��---*/
void guixia(void) 
{sound(1174,100);
  cls();
  while(1)
  {
  locate(2,6);
  printf("guixia");
  locate(4,1);printf("ks=%d  kz=%d  kx=%d " ,ks,kz,kx);
  locate(6,1);printf("%d %d %d %d %d %d %d %d" ,wkys,wkys,wkys,wkys,wkys,wkys,wkys,wkys); 
  locate(7,1);printf("dh_b=%3d dh_l=%3d" ,dh_b,dh_l);
  if(kx==0){motor(3,0);wait(0.5);break;}
  else {motor(3,200);}
  
  }  
}
void guizhong(void)
{sound(1174,100);
  cls();
  while(1)
  {
  locate(2,6);
  printf("guizhong");
  locate(4,1);printf("ks=%d  kz=%d  kx=%d " ,ks,kz,kx);
  locate(6,1);printf("%d %d %d %d %d %d %d %d" ,wkys,wkys,wkys,wkys,wkys,wkys,wkys,wkys);
  locate(7,1);printf("dh_b=%3d dh_l=%3d" ,dh_b,dh_l);
  if(kz==1){motor(3,0);wait(0.5);break;}
  else {motor(3,-400);}
  }  
}
void guishang(void)
{sound(1174,100);
  cls();
  while(1)
  {
  locate(2,6);
  printf("guishang");
  locate(4,1);printf("ks=%d  kz=%d  kx=%d " ,ks,kz,kx);
  locate(6,1);printf("%d %d %d %d %d %d %d %d" ,wkys,wkys,wkys,wkys,wkys,wkys,wkys,wkys); 
  locate(7,1);printf("   dh_b=%3d    dh_l=%3d" ,dh_b,dh_l);
  if(ks==1){motor(3,0);wait(0.5);break;}
  else {motor(3,-400);}
  }  
}
/*---���������---*/
void test_adc(void)
{
  sound(1174,100);
  cls();
 while(1)
 {yssb();
  locate(1,2);printf("chuanganqiceshi");
  locate(2,1);printf("1:%3d 2:%3d ",gdf1,gdf2);        
  locate(3,1);printf("3:%3d 4:%3d ",gdf3,gdf4);    
  locate(4,1);printf("1:%3d 2:%3d ",gdb1,gdb2);      
  locate(5,1);printf("3:%3d 4:%3d",gdb3,gdb4);  
  locate(6,1);printf("l:%3d r:%3d cj=%3d",gdl,gdr,cj);  
  locate(7,1);printf("dh_b=%3d dh_l=%3d" ,dh_b,dh_l);  
  locate(8,1);printf("wkys=%d s=%d z=%d x=%d " ,wkys,ks,kz,kx);              
  //wait(0.1);
  }
}

/*---�������---*/
//�����˵���Ϊ����λ���������м�ͣ1�룬צ���ſ��Ƕȣ��½���λ����������ͣ1�룬צ���ſ��Ƕ�
void test_sjzz(void)
{  
   sound(1174,100);
   cls();
  while(1)
  {
  guixia();
  guizhong();
  guixia();
  guishang();
  guixia();
  
   }   
}
/*---������---*/
//�����˵���Ϊ��ǰ��1�룬����1�룬��ת1�룬��ת1��
void test_dc(void)
{
  sound(1174,100);
 cls();
 while(1)
 {
  locate(1,2);
  printf("dianjiceshi");
  sound(500,500);
  run(400,400);wait(1);
  run(-400,-400);wait(1);
  run(400,0);wait(1);
  run(0,400);wait(1);
  run(0,0);wait(1);
  sound(500,500);
  //while(1){;}
  }
}

void test_jxs(void)
{
 while(1)
 { 
  cls();
  yssb();
  locate(1,7);
  printf("jixieshou");
  locate(4,3);
  printf("zhuajin");
  //servo(4,zwk);wait(2);
  locate(6,2);
  printf("wkys=%3d " ,wkys);
  servo(4,zwk);wait(1);
  servo(4,fwk);wait(1);
  servo(4,xwk);wait(1);
  servo(2,40);wait(1);
  //servo(2,65);wait(1);
  servo(2,80);wait(1);
  servo(3,120);wait(1);
  //servo(3,70);wait(1);
  //servo(3,60);wait(1);
 // servo(3,55);wait(1);
 // servo(3,50);wait(1);
  //servo(3,45);wait(1);
  servo(3,40);wait(1);
  /*cls();
  locate(1,7);
  printf("jixieshou");
  locate(4,3);
  printf("zhangkai");
  servo(4,fwk);wait(2);
  servo(2,80);wait(2);
  servo(3,80);wait(2);*/
 }
}

void zhua(void)
{
 run(0,0);servo(4,zwk);wait(0.6);
  yssb();
//int i_hei=0,i_lan=0,i_lv=0,i_bai=0,i_hong=0;  
 { 
  if(wkys==1) {i_hei++;if(i_hei==2) guizhong();else if(i_hei==3) guishang();else guixia();}
  else if(wkys==2) {i_lan++;if(i_lan==2) guizhong();else if(i_lan==3) guishang();else guixia();}
  else if(wkys==3) {i_lv++;if(i_lv==2) guizhong();else if(i_lv==3) guishang();else guixia();}
  else if(wkys==4) {i_bai++;if(i_bai==2) guizhong();else if(i_bai==3) guishang();else guixia();}
  else if(wkys==5) {i_hong++;if(i_hong==2) guizhong();else if(i_hong==3) guishang();else guixia();}
  else {run(0,0);servo(4,fwk);wait(0.2);zhua();}
 }
}
  
void fang(void)
{
 run(0,0);servo(4,fwk);wait(0.1);go_line_bm();wait(0.2);guixia();
 
//if(kx==1){go_line_bm();wait(0.2);guixia();}
//else {;} 
}

void run(int x,int y)
{
  motor(4,-x);   
  motor(1,-y);  
}
void f_a(void)
{
  servo(4,xwk);servo(3,120);servo(2,49);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  run(-200,-200);wait(1);
  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  servo(2,65);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
 if(wkys==1)hei_f();
 else if(wkys==2)lan_f();
 else if(wkys==3)lv_f();
 else if(wkys==4)bai_f();
 else hong_f();
}
void f_b(void)
{
  servo(4,xwk);servo(3,120);servo(2,73);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  run(-200,-200);wait(1);
  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  servo(2,60);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
  if(wkys==1)hei_f();
 else if(wkys==2)lan_f();
 else if(wkys==3)lv_f();
 else if(wkys==4)bai_f();
 else hong_f();
}
void f_c(void)
{
  servo(4,xwk);servo(3,120);servo(2,78);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  go_dwz_ce();run(150,180);wait(0.2);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
//  servo(3,45);wait(0.2);
//  servo(3,40);wait(0.2);
  run(-200,-200);wait(1.2);
  servo(2,60);wait(0.2);
  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
  if(wkys==1)hei_f();
 else if(wkys==2)lan_f();
 else if(wkys==3)lv_f();
 else if(wkys==4)bai_f();
 else hong_f();
}
void f_e(void)
{
  servo(4,xwk);servo(3,120);servo(2,45);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  go_dwz_ce();run(150,150);wait(0.2);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  run(-200,-200);wait(1.2);
  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  servo(2,65);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
 if(wkys==1)hei_f();
 else if(wkys==2)lan_f();
 else if(wkys==3)lv_f();
 else if(wkys==4)bai_f();
 else hong_f();
}
void f_d(void)
{
  servo(4,xwk);servo(3,120);servo(2,59);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(150,150);wait(0.8);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  run(-200,-200);wait(1.5);
  servo(2,64);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
 if(wkys==1)hei_fd();
 else if(wkys==2)lan_fd();
 else if(wkys==3)lv_fd();
 else if(wkys==4)bai_fd();
 else hong_fd();
}
void g_a(void)
{
  servo(4,xwk);servo(3,120);servo(2,73);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  run(-200,-200);wait(1);
  servo(2,60);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
  if(wkys==1)hei_g();
 else if(wkys==2)lan_g();
 else if(wkys==3)lv_g();
 else if(wkys==4)bai_g();
 else hong_g();
}
void g_b(void)
{
  servo(4,xwk);servo(3,120);servo(2,50);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,45);wait(0.2);
  run(-200,-200);wait(1);
 //  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  servo(2,65);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
 if(wkys==1)hei_g();
 else if(wkys==2)lan_g();
 else if(wkys==3)lv_g();
 else if(wkys==4)bai_g();
 else hong_g();
}
void g_e(void)
{
  servo(4,xwk);servo(3,120);servo(2,78);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  go_dwz_ce();run(150,150);wait(0.1);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,45);wait(0.2);
  run(-200,-200);wait(1.2);
  //servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  servo(2,60);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
  if(wkys==1)hei_g();
 else if(wkys==2)lan_g();
 else if(wkys==3)lv_g();
 else if(wkys==4)bai_g();
 else hong_g();
}
void g_c(void)
{
  servo(4,xwk);servo(3,120);servo(2,40);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(100,100);wait(0.1);
  go_dwz_ce();run(150,150);wait(0.2);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,45);wait(0.2);
  run(-200,-200);wait(1.2);
  servo(2,65);wait(0.2);
//  servo(3,45);wait(0.2);
  servo(3,40);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
 if(wkys==1)hei_g();
 else if(wkys==2)lan_g();
 else if(wkys==3)lv_g();
 else if(wkys==4)bai_g();
 else hong_g();
}
void g_d(void)
{
  servo(4,xwk);servo(3,120);servo(2,60);
  go_dwz_z();run(100,100); wait(0.1);
  go_dwz_zj();run(150,150);wait(0.8);
  run(0,0);
  servo(3,60);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,45);wait(0.2);
 // servo(3,40);wait(0.2);
  run(-200,-200);wait(1.5);
  servo(3,40);wait(0.2);
  servo(2,64);wait(0.2);
  servo(3,50);wait(0.2);
  servo(3,55);wait(0.2);
  servo(3,60);wait(0.2);
  servo(3,120);wait(0.2);
  run(300,300);while(cj<640){;}wait(0.2);
  run(0,0);zhua();
 if(wkys==1)hei_gd();
 else if(wkys==2)lan_gd();
 else if(wkys==3)lv_gd();
 else if(wkys==4)bai_gd();
 else hong_gd();
}

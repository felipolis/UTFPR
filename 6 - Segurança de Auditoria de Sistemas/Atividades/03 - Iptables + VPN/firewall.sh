echo "Habilitando firewall como roteador"
echo 1 > /proc/sys/net/ipv4/ip_forward

echo "Limpando regras existentes"
iptables -F
iptables -t nat -F
iptables -t mangle -F

echo "Política padrão: bloquear tudo no INPUT, liberar tudo nas demais sitcoes"
iptables -P INPUT DROP
iptables -P FORWARD ACCEPT
iptables -P OUTPUT ACCEPT

echo "Habilitando o NAT para LAN1 e DMZ"
iptables -t nat -A POSTROUTING -o eth0 -s 172.16.0.0/24 -j MASQUERADE
iptables -t nat -A POSTROUTING -o eth0 -s 10.0.0.0/24 -j MASQUERADE
iptables -t nat -A PREROUTING -i eth0 -p tcp --dport 3306 -j DNAT --to 10.0.0.5
iptables -t nat -A PREROUTING -i eth0 -p tcp --dport 80 -j DNAT --to 10.0.0.4

echo "Regras para LAN1: screened"
iptables -A FORWARD -o eth1 -m state --state NEW,INVALID -j DROP
iptables -A FORWARD -i eth1 -s 172.16.0.0/24 -o eth0 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
iptables -A FORWARD -o eth1 -d 172.16.0.0/24 -i eth0 -m state --state ESTABLISHED,RELATED -j ACCEPT

echo "Regras para DMZ"
echo -e "\tOs hosts da DMZ devem ser clientes apenas da Internet"
iptables -A FORWARD -i eth2 -s 10.0.0.0/24 -o eth0 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
iptables -A FORWARD -i eth0 -o eth2 -d 10.0.0.0/24 -m state --state ESTABLISHED,RELATED -j ACCEPT
echo -e "\tPermitir acesso ao Host D (Servidor HTTP) na DMZ"
iptables -A FORWARD -o eth2 -d 10.0.0.4 -p tcp --dport 80 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
iptables -A FORWARD -i eth2 -s 10.0.0.4 -p tcp --sport 80 -m state --state ESTABLISHED,RELATED -j ACCEPT
echo -e "\tPermitir acesso ao Host E (Servidor MySQL) na DMZ"
iptables -A FORWARD -o eth2 -d 10.0.0.5 -p tcp --dport 3306 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
iptables -A FORWARD -i eth2 -s 10.0.0.5 -p tcp --sport 3306 -m state --state ESTABLISHED,RELATED -j ACCEPT

echo "Permitir acesso do firewall a sítios Web na Internet (controle por estados)"
iptables -A OUTPUT -o eth0 -p tcp --dport 80 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
iptables -A INPUT -i eth0 -p tcp --sport 80 -m state --state ESTABLISHED,RELATED -j ACCEPT
iptables -A OUTPUT -o eth0 -p tcp --dport 443 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
iptables -A INPUT -i eth0 -p tcp --sport 443 -m state --state ESTABLISHED,RELATED -j ACCEPT

echo "Apenas Host A pode acessar o firewall via SSH (controle por MAC)"
iptables -A INPUT -i eth1 -s 172.16.0.1 -p tcp --dport 22 -m mac --mac-source 00:00:00:00:00:01 -j ACCEPT
iptables -A OUTPUT -o eth1 -d 172.16.0.1 -p tcp --sport 22  -j ACCEPT

echo "Apenas Hosts da LAN1 podem acessar hosts da DMZ via SSH (controle por MAC)"
iptables -A FORWARD -i eth1 -o eth2 -s 172.16.0.1 -d 10.0.0.0/24 -p tcp --dport 22 -m mac --mac-source 00:00:00:00:00:01 -j ACCEPT
iptables -A FORWARD -i eth2 -o eth1 -d 172.16.0.1 -s 10.0.0.0/24 -p tcp --sport 22 -m mac --mac-source 00:00:00:00:00:04 -j ACCEPT
iptables -A FORWARD -i eth2 -o eth1 -d 172.16.0.1 -s 10.0.0.0/24 -p tcp --sport 22 -m mac --mac-source 00:00:00:00:00:05 -j ACCEPT
iptables -A FORWARD -i eth1 -o eth2 -s 172.16.0.2 -d 10.0.0.0/24 -p tcp --dport 22 -m mac --mac-source 00:00:00:00:00:02 -j ACCEPT
iptables -A FORWARD -i eth2 -o eth1 -d 172.16.0.2 -s 10.0.0.0/24 -p tcp --sport 22 -m mac --mac-source 00:00:00:00:00:04 -j ACCEPT
iptables -A FORWARD -i eth2 -o eth1 -d 172.16.0.2 -s 10.0.0.0/24 -p tcp --sport 22 -m mac --mac-source 00:00:00:00:00:05 -j ACCEPT

echo "Proibir acesso via Telnet e FTP entre as redes (controle por estados)"
iptables -A FORWARD -i eth1 -o eth2 -p tcp --dport 23 -m state --state NEW,INVALID -j DROP
iptables -A FORWARD -i eth1 -o eth2 -p tcp --dport 21 -m state --state NEW,INVALID -j DROP
iptables -A FORWARD -i eth2 -o eth1 -p tcp --sport 23 -m state --state NEW,INVALID -j DROP
iptables -A FORWARD -i eth2 -o eth1 -p tcp --sport 21 -m state --state NEW,INVALID -j DROP

echo "VPN"
iptables -A INPUT -p udp --dport 1194 -j ACCEPT
iptables -A OUTPUT -p udp --sport 1194 -j ACCEPT

iptables -A FORWARD -i tun0 -j ACCEPT
iptables -A FORWARD -o tun0 -j ACCEPT

echo "Permitir ICMP e DNS em todas as interfaces"
iptables -A INPUT -p icmp -j ACCEPT
iptables -A FORWARD -p icmp -j ACCEPT
iptables -A OUTPUT -p icmp -j ACCEPT
iptables -A INPUT -p udp --sport 53 -j ACCEPT
iptables -A FORWARD -p udp --dport 53 -j ACCEPT
iptables -A OUTPUT -p udp --dport 53 -j ACCEPT

echo "Negar tudo no final (caso algo não tenha sido especificamente permitido)"
iptables -A INPUT -j DROP
iptables -A FORWARD -j DROP
iptables -A OUTPUT -j DROP


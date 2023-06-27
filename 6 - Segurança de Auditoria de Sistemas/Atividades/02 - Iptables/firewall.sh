echo "Setando variaveis"

echo "Habilitando firewall como roteador"
echo 1 > /proc/sys/net/ipv4/ip_forward

echo "Zerando firewall"
iptables -F
iptables -t nat -F
iptables -t mangle -F

echo "Setando politica"
iptables -P INPUT DROP
iptables -P OUTPUT DROP
iptables -P FORWARD DROP

echo "Firewall fazendo nat"
echo -e "\tMascarando pacotes para internet"
iptables -t nat -A POSTROUTING -o eth1 -j MASQUERADE
echo -e "\tRedirecionamento de DNS"
iptables -t nat -A PREROUTING -i eth0 -p udp --dport 53 -j DNAT --to 8.8.8.8
iptables -t nat -A PREROUTING -i eth0 -p udp --dport 53 -j DNAT --to 1.1.1.1
echo -e "\tRedirecionamento ao http do host A"
iptables -t nat -A PREROUTING -i eth1 -p tcp --dport 80 -j DNAT --to 10.1.0.1

echo "Firewall como roteador"
echo -e "\tLiberar o acesso do host B a internet"
iptables -t filter -A FORWARD -s 10.1.0.2 -p tcp --dport 80 -j ACCEPT
iptables -t filter -A FORWARD -d 10.1.0.2 -p tcp --sport 80 -j ACCEPT
iptables -t filter -A FORWARD -s 10.1.0.2 -p tcp --dport 443 -j ACCEPT
iptables -t filter -A FORWARD -d 10.1.0.2 -p tcp --sport 443 -j ACCEPT
echo -e "\tLiberar o acesso do host B ao DNS"
iptables -t filter -A FORWARD -s 10.1.0.2 -p udp --dport 53 -j ACCEPT
iptables -t filter -A FORWARD -d 10.1.0.2 -p udp --sport 53 -j ACCEPT
echo -e "\tLiberar o acesso do host A a internet"
iptables -t filter -A FORWARD -s 10.1.0.1 -p tcp --dport 80 -j ACCEPT
iptables -t filter -A FORWARD -d 10.1.0.1 -p tcp --sport 80 -j ACCEPT
iptables -t filter -A FORWARD -s 10.1.0.1 -p tcp --dport 443 -j ACCEPT
iptables -t filter -A FORWARD -d 10.1.0.1 -p tcp --sport 443 -j ACCEPT
echo -e "\tLiberar o acesso do host A ao DNS"
iptables -t filter -A FORWARD -s 10.1.0.1 -p udp --dport 53 -j ACCEPT
iptables -t filter -A FORWARD -d 10.1.0.1 -p udp --sport 53 -j ACCEPT
echo -e "\tLiberar acesso dos hosts de outras redes ao host A via HTTP/HTTPS"
iptables -t filter -A FORWARD -d 10.1.0.1 -p tcp --dport 80 -j ACCEPT
iptables -t filter -A FORWARD -s 10.1.0.1 -p tcp --sport 80 -j ACCEPT
iptables -t filter -A FORWARD -d 10.1.0.1 -p tcp --dport 443 -j ACCEPT
iptables -t filter -A FORWARD -s 10.1.0.1 -p tcp --sport 443 -j ACCEPT


echo "Firewall como servidor"
echo -e "\tPermitindo acesso ssh no firewall"
iptables -A INPUT -i eth0 -p tcp --dport 22 -j ACCEPT
iptables -A OUTPUT -o eth0 -p tcp --sport 22 -j ACCEPT

echo "Firewall como cliente"
echo -e "\tPermitindo que o firewall acesse sitios da internet"
iptables -A OUTPUT -p tcp --dport 80 -j ACCEPT
iptables -A INPUT -p tcp --sport 80 -j ACCEPT
iptables -A OUTPUT -p tcp --dport 443 -j ACCEPT
iptables -A INPUT -p TCP --sport 443 -j ACCEPT
echo -e "\tPermitindo que o firerwall acesse o DNS"
iptables -A OUTPUT -p udp --dport 53 -j ACCEPT
iptables -A INPUT -p udp --sport 53 -j ACCEPT
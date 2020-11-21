apt-get install iptables
iptables --policy INPUT DROP
iptables --policy FORWARD DROP

iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT



iptables -A INPUT -p tcp --dport 2222 -m state --state NEW -m recent --update --seconds 60 --hitcount 4 -j DROP
iptables -A INPUT -p tcp --dport 2222 -m state --state NEW -m recent --set
iptables -A INPUT -p tcp --dport 2222 -m state --state NEW -j ACCEPT

iptables -A INPUT -p tcp --dport 80 -m state --state NEW -m recent --update --seconds 5 --hitcount 20 -j DROP
iptables -A INPUT -p tcp --dport 80 -m state --state NEW -m recent --set
iptables -A INPUT -p tcp --dport 80 -m state --state NEW -j ACCEPT

iptables -A INPUT -p tcp --dport 443 -m state --state NEW -m recent --update --seconds 5 --hitcount 20 -j DROP
iptables -A INPUT -p tcp --dport 443 -m state --state NEW -m recent --set
iptables -A INPUT -p tcp --dport 443 -m state --state NEW -j ACCEPT

iptables -A INPUT -p icmp --icmp-type 8 -m state --state NEW,ESTABLISHED,RELATED

iptables -A INPUT -j DROP
iptables -A FORWARD -j DROP

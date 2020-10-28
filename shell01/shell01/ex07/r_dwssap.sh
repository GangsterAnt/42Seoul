cat /etc/passwd| awk 'NR >=12 {print $0}' | rev | sort -r

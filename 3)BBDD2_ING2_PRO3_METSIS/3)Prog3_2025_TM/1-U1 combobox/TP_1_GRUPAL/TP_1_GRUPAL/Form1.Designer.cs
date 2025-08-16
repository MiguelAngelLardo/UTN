namespace TP_1_GRUPAL
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnEjercicio1 = new System.Windows.Forms.Button();
            this.btnEjercicio2 = new System.Windows.Forms.Button();
            this.btnEjercicio3 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnEjercicio1
            // 
            this.btnEjercicio1.Location = new System.Drawing.Point(34, 35);
            this.btnEjercicio1.Name = "btnEjercicio1";
            this.btnEjercicio1.Size = new System.Drawing.Size(93, 23);
            this.btnEjercicio1.TabIndex = 0;
            this.btnEjercicio1.Text = "EJERCICIO 1";
            this.btnEjercicio1.UseVisualStyleBackColor = true;
            this.btnEjercicio1.Click += new System.EventHandler(this.btnEjercicio1_Click);
            // 
            // btnEjercicio2
            // 
            this.btnEjercicio2.Location = new System.Drawing.Point(156, 35);
            this.btnEjercicio2.Name = "btnEjercicio2";
            this.btnEjercicio2.Size = new System.Drawing.Size(93, 23);
            this.btnEjercicio2.TabIndex = 1;
            this.btnEjercicio2.Text = "EJERCICIO 2";
            this.btnEjercicio2.UseVisualStyleBackColor = true;
            this.btnEjercicio2.Click += new System.EventHandler(this.btnEjercicio2_Click);
            // 
            // btnEjercicio3
            // 
            this.btnEjercicio3.Location = new System.Drawing.Point(282, 35);
            this.btnEjercicio3.Name = "btnEjercicio3";
            this.btnEjercicio3.Size = new System.Drawing.Size(93, 23);
            this.btnEjercicio3.TabIndex = 2;
            this.btnEjercicio3.Text = "EJERCICIO 3";
            this.btnEjercicio3.UseVisualStyleBackColor = true;
            this.btnEjercicio3.Click += new System.EventHandler(this.btnEjercicio3_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(443, 244);
            this.Controls.Add(this.btnEjercicio3);
            this.Controls.Add(this.btnEjercicio2);
            this.Controls.Add(this.btnEjercicio1);
            this.Name = "Form1";
            this.Text = "Formulario Principal";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnEjercicio1;
        private System.Windows.Forms.Button btnEjercicio2;
        private System.Windows.Forms.Button btnEjercicio3;
    }
}

